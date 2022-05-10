//
// Created by Ly on 2020/10/10.
//

#include "channel.hpp"

Channel::Channel(int fd, int event, event_read_callback eventReadCallback, event_write_callback eventWriteCallback,
                 void *data) {
    int fd_ = fd;
    int event_ = event;   //表示event类型
    eventReadCallback_ = eventReadCallback;
    eventWriteCallback_ = eventWriteCallback;
    data_ = data; //callback data, 可能是event_loop，也可能是tcp_server或者tcp_connection
}