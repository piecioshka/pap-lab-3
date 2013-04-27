/* client - lab3-4 - zadanie 1 */

#include <sys/socket.h>
#include <stdio.h>

#include "../../library/utils.h"

int create_socket() {
    return socket(PF_INET, SOCK_STREAM, 0);
}

int main () {
    /* test_console_lib(); */
    int first_socket;

    printf("create client instance\n");

    first_socket = create_socket();

    printf("%d\n", first_socket);

    return 0;
}
