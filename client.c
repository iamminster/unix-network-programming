//
// Created by nguyen minh on 2020/02/13.
//

#include <netdb.h>
#include <string.h>
#include <stdio.h>

int main() {
    int status;
    int sockfd;
    struct addrinfo hints;
    struct addrinfo *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // get server address info
    status = getaddrinfo("wwww.google.com", "3490", &hints, &res);
    printf("%d\n", status);

    // create a socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    printf("%d\n", sockfd);

    // connect to server on socket
    status = connect(sockfd, res->ai_addr, res->ai_addrlen);

    printf("%d\n", status);

    freeaddrinfo(res);

}

