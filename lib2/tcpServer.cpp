//
// Created by Ly on 2020/10/10.
//

#include "tcpServer.hpp"
#include <sys/socket.h>
#include <netinet/in.h>    /* sockaddr_in{} and other Internet defns */
#include <signal.h> // signal
#include <fcntl.h>
#include  <string.h>  // bzero
#include "commom.hpp"

void TcpServer::make_nonblocking(int fd) {
    fcntl(fd, F_SETFL, O_NONBLOCK);
}

int TcpServer::tcp_nonblocking_server_listen(int port) {
    int listenfd;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    make_nonblocking(listenfd);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    int on = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    int rt1 = bind(listenfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (rt1 < 0) {
        return -1;
    }

    int rt2 = listen(listenfd, LISTENQ);
    if (rt2 < 0) {
        return -1;
    }

    signal(SIGPIPE, SIG_IGN);

    return listenfd;
}