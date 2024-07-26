message(STATUS "Compiling tcp")

add_library(
  ${TCP_NAME}
  SHARED
  client.h client.cpp
  server.h server.cpp
)