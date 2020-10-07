if (EPOLL_EXISTS)
    set(server_lib
        eventLoop.cpp
        tcpServer.cpp
        epollDispatcher.cpp
        )
else ()
    set(server_lib
        eventLoop.cpp
        tcpServer.cpp
        epollDispatcher.cpp
        )
endif ()

add_library(server ${server_lib})

install(TARGETS server DESTINATION lib)