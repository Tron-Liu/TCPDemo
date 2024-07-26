#include <stdio.h>

#include "server.h"

#include <ev.h>

int main() {

  Server server("127.0.0.1", 9999);
  server.Run();
  
}
