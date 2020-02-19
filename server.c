#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>

#define MYPORT "3490"
#define BACKLOG 10

int main(void) {

    struct sockaddr_storage their_addr;
    socklen_t  addr_size;

    struct addrinfo hints, *res;
    int sockfd, new_fd;


    memset(&hints, 0, sizeof(hints)); // make sure struct is empty
    hints.ai_family = AF_UNSPEC; // don't care IP4 or IP6
    hints.ai_socktype = SOCK_STREAM; // using TCP stream sockets
    hints.ai_flags = AI_PASSIVE; // fill in my IP

    // get address info
    getaddrinfo(NULL, MYPORT, &hints, &res);

    // make a socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    // bind this socket to a port
    bind(sockfd, res->ai_addr, res->ai_addrlen);

    // listen on port
    listen(sockfd, BACKLOG);

    // accept an incoming connection
    addr_size = sizeof(their_addr);
    new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);

    // ready to communicate


    printf("Hello, World!\n");
    return 0;
}
