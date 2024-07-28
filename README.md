# TCPDemo

A TCP SDK Demo project based on libev

## feature

1. 使用 libev 实现一个高可用 TCP 服务 SDK
2. 并设定其基础通信协议
3. 完成 SDK 使用样例，客户端/服务端

## 使用 libev 构建 TCP 响应基本流程

1. 创建 socket
2. 绑定 socket
3. 监听 socket
4. 重建一个 watcher，用来承载 accept 事件
5. 写一个 callback 用来做实际的 accept 调用
6. 重建并初始化一个 watcher 用来从 client 中读取请求
7. 写一个 callback 用来 read
8. 启动 event loop
