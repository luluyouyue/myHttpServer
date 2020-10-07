# PPC(process per connection)模式
一个连接用一个进程，缺点是进程创建太慢，且进程之间通信太复杂

# TPC(thread per connection)模式
一个连接采用一个线程，优点是线程之间通信成本低，缺点是线程之间需要进行条件竞争、同步

# reactor模式
为了在单机器上取得不错的性能，目前工业界主流的方式是采用reactor

![image](./images/1.jpg)