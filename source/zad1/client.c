/* client - lab3-4 - zadanie 1 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "../../library/utils.h"

#define PORT 13
#define DESC_IP "127.0.0.1"

int main () {
    /* test_console_lib(); */
    int sock_id;
    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(DESC_IP);
    address.sin_port = htons(PORT);
    memset( &( address.sin_zero ), '\0', 8 );

    printf("=== create client instance ===\n\n");

    /* create socket to connection */
    sock_id = create_socket_tcp();

    /* use create socket to connect address */
    create_connection(sock_id, address);

    /* close connection */
    close_connection(sock_id);

    return 0;
}
