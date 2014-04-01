/**
 * 1. Opracuj wersję klienta i serwera standardowej usługi time w wersji UDP
 * (opis usługi time jest zawarty w RFC 868 - www.rfc-editor.org).
 */

#include "../lib/libnetutils.h"

#define PORT 37
#define MAX_QUEUE 128

int main () {
    int sock_id;

    printf("=== create server ===\n\n");

    /* create socket */
    sock_id = create_socket_udp();

    /* bind server to defined port */
    bind_port(sock_id, PORT);

    /* server waiting for client */
    listen_for_client_tcp(sock_id, MAX_QUEUE);

    /* handle client */
    handle_incoming_client(sock_id, 0);

    return 0;
}
