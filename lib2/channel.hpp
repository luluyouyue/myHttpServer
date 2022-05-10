//
// Created by Ly on 2020/10/10.
//

#ifndef MYHTTPSERVER_CHANNEL_HPP
#define MYHTTPSERVER_CHANNEL_HPP

#include "commom.hpp"

typedef int (*event_read_callback)(void *data);
typedef int (*event_write_callback)(void *data);

class Channel {
public:
    Channel(int fd, int events, event_read_callback eventReadCallback, event_write_callback eventWriteCallback,
            void *data);
    int getFd() {
        return fd_;
    }

    int getEvent() {
        return event_;
    }

private:
    int fd_;
    int event_;   //表示event类型

    event_read_callback eventReadCallback_;
    event_write_callback eventWriteCallback_;
    void *data_; //callback data, 可能是event_loop，也可能是tcp_server或者tcp_connection
};

#endif //MYHTTPSERVER_CHANNEL_HPP
