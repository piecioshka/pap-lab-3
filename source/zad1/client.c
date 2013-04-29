/* client - lab3-4 - zadanie 1 */

#include <sys/socket.h>
#include <stdio.h>

#include "../../library/utils.h"

int create_socket() {
    int socket_id;

    /* run socket function */
    socket_id = socket(PF_INET, SOCK_STREAM, 0);

    /* if error occur - send message to user */
    if (socket_id == -1) {
        fprintf(stderr, "ERROR: unable to create socket\n");
        exit(0);
    }

    printf("create socket: %d\n", socket_id);

    return socket_id;
}

int main () {
    /* test_console_lib(); */
    int i = 10;

    printf("create client instance\n");

    while (--i) {
        create_socket();
    }

    return 0;
}
