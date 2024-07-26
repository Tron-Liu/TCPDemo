cmake_minimum_required(VERSION 3.5.0)

project(TCPDemo VERSION 0.1.0)

add_executable(server server_demo.cpp)
add_executable(client client_demo.cpp)

# path
set(PROTOCOL_PTAH ${CMAKE_CURRENT_SOURCE_DIR}/protocol)
set(TCP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/tcp)

# name
set(PROTOCOL_NAME protocol)
set(TCP_NAME tcp)

add_subdirectory(protocol)
add_subdirectory(tcp)

target_include_directories(server PUBLIC ${TCP_PATH})
target_include_directories(client PUBLIC ${TCP_PATH})

target_link_libraries(server ${TCP_NAME})
target_link_libraries(client ${TCP_NAME})