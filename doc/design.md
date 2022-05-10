# PPC(process per connection)模式
一个连接用一个进程，缺点是进程创建太慢，且进程之间通信太复杂

# TPC(thread per connection)模式
一个连接采用一个线程，优点是线程之间通信成本低，缺点是线程之间需要进行条件竞争、同步

# reactor模式
为了在单机器上取得不错的性能，目前工业界主流的方式是采用reactor。根据使用reactor和使用线程的情况，
理论上共有4中模型：
- 单reactor单线程模型
- 单reactor多线程模型
- 多reator单线程（这个其实没必要，只是理论上的模型）
- 多reactor多线程

## 设计

数据结构的设计：
- eventLoop：对应一个reactor
- 线程池：每个线程包含一个reactor
- channel: 一个事件，每个事件对应一个读、写事件，用于回调
-dispatcher: 就是一个时间监听器，本质就是select、poll、epoll等IO复用

主要有两点：
1、main-reactor如何唤醒其他的sub-reactor？
利用socketPair实现主线程对子线程的通知


2、缓冲区设计
缓冲区

![image](./images/1.jpg)

3、epoll  IO多路复用技术
epoll好处:
    1 事件注册，不需要全部重新进行注册
    2 事件返回：返回的是有活动的事件
    3 

如何实现边缘触发？


边缘触发饥饿问题和解决方案?
边缘触发饥饿问题：
解决方案：

# proacor异步IO
内核自动帮忙执行拷贝（read）/ 读取（write）操作，然后通知应用程序

怎么通知呢？需要应用程序调用相关接口自己通知


# 参考
https://github.com/chen3feng/toft.git
