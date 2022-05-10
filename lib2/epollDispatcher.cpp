//
// Created by Ly on 2020/10/10.
//

#include "epollDispatcher.hpp"
#include  <sys/epoll.h>
#include "commom.hpp"

int EpollDispatcher::dispatcher() {

}

int EpollDispatcher::init() {
    efd_ = 0;

    efd_ = epoll_create1(0);
    if (efd_ == -1) {
        return -1;
    }

    events_ = (struct epoll_event*)calloc(MAXEVENTS, sizeof(struct epoll_event));
    return 0;
}

int EpollDispatcher::addChannelToMap(Channel channel) {
    int fd = channel.getFd();
    if (fd < 0) {
        return -1;
    }

    if (channel_map_ptr_->find(fd) != channel_map_ptr_->end()) {
        return 0;
    }

    channel_map_ptr_->insert({fd, channel});
    return 0;
}

int EpollDispatcher::addChannelToEpoll(Channel channel) {
    int channel_fd = channel.getFd();
    int channel_event = channel.getEvent();

    int events = 0;
    if (channel_event & EVENT_READ) {
        events = events | EPOLLIN;
    }
    if (channel_event & EVENT_WRITE) {
        events = events | EPOLLOUT;
    }

    struct epoll_event event;
    event.data.fd = channel_fd;
    event.events = events;
//    event.events = events | EPOLLET;
    if (epoll_ctl(efd_, EPOLL_CTL_ADD, channel_fd, &event) == -1) {
        return -1;
    }

    return 0;
}

int  EpollDispatcher::addEvent(Channel channel) {
    int fd = channel.getFd();
    if (fd < 0) {
        return -1;
    }
    if (addChannelToMap(channel) < 0) {
        return -1;
    }
    if (addChannelToEpoll(channel) < 0) {
        return -1;
    }
    return 0;
}