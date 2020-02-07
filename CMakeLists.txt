cmake_minimum_required(VERSION 3.5)
project(dev-contain-init)

set(CMAKE_CXX_STANDARD 14)

add_executable(dev_contain_init
  src/dev-contain-init.cpp)
target_link_libraries(dev_contain_init -static)
target_compile_options(dev_contain_init
  PUBLIC -Wall -Wextra)
