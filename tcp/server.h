#ifndef _SERVER_H_
#define _SERVER_H_

#include <ev.h>
#include <string>

class Server {
public:
  Server(std::string ip_address, int port);
  ~Server();

  void Run();

private:
  void Create_();
  void Bind_();
  void Listen_();
  void Accept_();

  static void Accept_CB_(struct ev_loop *loop, ev_io *watcher, int events);

private:
  std::string ip_address_;
  int port_;

  int fd_;
  int listen_num_;

  struct ev_io stdin_watcher_;
  struct ev_timer timeout_watcher_;
  struct ev_loop *loop_;
};

#endif
