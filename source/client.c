#include <stdio.h>      /* printf(), fprintf() */
#include <sys/socket.h> /* socket(), connect(), sendto(), recvfrom() */
#include <arpa/inet.h>  /* sockaddr_in, inet_addr() */
#include <stdlib.h>     /* atoi() */
#include <string.h>     /* memset() */
#include <unistd.h>     /* close() */

#define ECHOMAX 255     /* the longest text sended */

int main (int argc, char * argv[]) {
  int gniazdo;
  struct sockaddr_in echoSerwAdr;
  struct sockaddr_in echoOdpAdr;
  unsigned short echoSerwPort;
  unsigned int odpDl;
  char * serwIP;
  char * echoTekst;
  char echoBufor[ECHOMAX + 1];
  int echoTekstDl;
  int odpTekstDl;

  if ((argc < 3) || (argc > 4)) {
    fprintf(stderr, "Uzycie: %s <serwer AIP> <message> [<echo port>]\n", argv[0]);
    exit(1);
  }

  serwIP = argv[1];
  echoTekst = argv[2];

  if ((echoTekstDl = strlen(echoTekst)) > ECHOMAX) {
    printf("Tekst zbyt dlugi\n");
    exit(1);
  }

  if (argc == 4) {
    echoSerwPort = atoi(argv[3]);
  } else {
    echoSerwPort = 7;
  }

  if ((gniazdo = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
    perror("socket()");
    exit(1);
  }

  memset(&echoSerwAdr, 0, sizeof(echoSerwAdr));
  echoSerwAdr.sin_family = AF_INET;
  echoSerwAdr.sin_addr.s_addr = inet_addr(serwIP);
  echoSerwAdr.sin_port = htons(echoSerwPort);

  if (sendto(gniazdo, echoTekst, echoTekstDl, 0, (struct sockaddr *) & echoSerwAdr, sizeof(echoSerwAdr)) != echoTekstDl) {
    perror("sendto()");
    exit(1);
  }


  odpDl = sizeof(echoOdpAdr);

  if ((odpTekstDl = recvfrom(gniazdo, echoBufor, ECHOMAX, 0, (struct sockaddr * ) & echoOdpAdr, & odpDl)) != echoTekstDl) {
    perror("recvfrom()");
    exit(1);
  }

  if (echoSerwAdr.sin_addr.s_addr != echoOdpAdr.sin_addr.s_addr) {
    fprintf(stderr, "Blad: pakiet z nieznanego zrodla.\n");
    exit(1);
  }

  echoBufor[odpTekstDl] = '\0';
  printf("Otrzymano: %s\n", echoBufor);

  close(gniazdo);
  exit(0);
}

  
