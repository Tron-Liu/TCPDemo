#include "server.h"

#include <arpa/inet.h>
#include <cerrno>
#include <cstdlib>
#include <ev.h>
#include <iostream>
#include <netinet/in.h>
#include <ostream>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

Server::Server(std::string ip_address, int port)
    : ip_address_(ip_address), port_(port) {
  fd_ = 0;
  listen_num_ = 10;
}

Server::~Server() {
  if (fd_)
    close(fd_);
}

void Server::Run() {
  Create_();
  Bind_();
  Listen_();
  Accept_();
}

void Server::Create_() {
  int sock = socket(PF_INET, SOCK_STREAM, 0);

  if (-1 == sock) {
    std::cerr << "Create socket failed, exit.";
    fd_ = 0;
    exit(1);
  }

  fd_ = sock;
}

void Server::Bind_() {
  struct sockaddr_in address;
  bzero(&address, sizeof(address));
  address.sin_family = AF_INET;
  inet_pton(AF_INET, ip_address_.c_str(), &address.sin_addr);
  address.sin_port = htons(port_);

  int ret = bind(fd_, (struct sockaddr *)&address, sizeof(address));

  if (-1 == ret) {
    std::cerr << "Bind socket failed, exit" << std::endl;
    exit(1);
  } else {
    std::cout << "Bind socket success." << std::endl;
  }
}

void Server::Listen_() {
  int ret = listen(fd_, listen_num_);
  if (-1 == ret) {
    std::cerr << "Listen socket failed, exit" << std::endl;
    exit(1);
  } else {
    std::cout << "Listen socket success." << std::endl;
  }
}

void Server::Accept_() {
  ev_io_init(&stdin_watcher_, Accept_CB_, fd_, EV_READ);
  ev_io_start(loop_, &stdin_watcher_);

  ev_loop(loop_, 0);
}

void Server::Accept_CB_(struct ev_loop *loop, ev_io *watcher, int events)
{
  struct sockaddr_in client_addr;
  socklen_t addrLength = sizeof(client_addr);
  int ret = accept(watcher->fd, (struct sockaddr*)(&client_addr), &addrLength);
  
  if(ret < 0) {
    std::cerr << "Accept socket failed." << std::endl;
    exit(1);
  }

  // handler read
}
