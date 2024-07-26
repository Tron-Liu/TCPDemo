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

  int listen();

private:
  std::string ip_address_;
  int port_;
};

#endif
