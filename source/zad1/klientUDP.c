/**
 * 1. Opracuj wersję klienta i serwera standardowej usługi time w wersji UDP
 * (opis usługi time jest zawarty w RFC 868 - www.rfc-editor.org).
 * http://www.rfc-editor.org/rfc/rfc868.txt
 */

#include "../lib/libnetutils.h"

#define PORT 37
#define DESC_IP "127.0.0.1"

int main () {
    int sock_id;

    printf("=== create client instance ===\n\n");

    /* create socket to connection */
    sock_id = create_socket_udp();

    /* use create socket to connect address */
    create_connection_tcp(sock_id, DESC_IP, PORT);

    /* send empty datagram */
    send_empty_datagram(sock_id);

    /* receive data from server */
    receive_from_server(sock_id);

    /* close connection */
    close_connection(sock_id);

    return 0;
}
