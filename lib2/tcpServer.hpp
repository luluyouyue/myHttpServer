//
// Created by Ly on 2020/10/10.
//

#ifndef MYHTTPSERVER_TCPSERVER_HPP
#define MYHTTPSERVER_TCPSERVER_HPP

class TcpServer {
public:
    void make_nonblocking(int fd);
    int tcp_nonblocking_server_listen(int port);
private:
};

#endif //MYHTTPSERVER_TCPSERVER_HPP
