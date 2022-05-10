//
// Created by Ly on 2020/10/7.
//

#ifndef MYHTTPSERVER_BASEDISPATCHER_HPP
#define MYHTTPSERVER_BASEDISPATCHER_HPP

#include <memory>
#include "channel.hpp"
#include <map>

class BaseDispatcher {
public:
    virtual int  dispatcher();
    virtual int  addChannelToMap(Channel channel);
    std::unique_ptr<std::map<int, Channel> > channel_map_ptr_;

    virtual int addChannelToEpoll(Channel channel);
    virtual int addEvent(Channel channel);
};

#endif //MYHTTPSERVER_BASEDISPATCHER_HPP
