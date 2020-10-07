//
// Created by Ly on 2020/10/7.
//

#ifndef MYHTTPSERVER_EPOLLDISPATCHER_HPP
#define MYHTTPSERVER_EPOLLDISPATCHER_HPP

#include "baseDispatcher.hpp"

class  EpollDispatcher : public BaseDispatcher {
public:
    EpollDispatcher() {}
    int dispatcher();
    int init();
    int addChannelToMap(Channel channel);
    int addChannelToEpoll(Channel channel);
    int addEvent(Channel channel);
private:
    int efd_;
    struct epoll_event *events_;
};
#endif //MYHTTPSERVER_EPOLLDISPATCHER_HPP
