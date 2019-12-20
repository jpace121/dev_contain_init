cmake_minimum_required(VERSION 3.5)
project(dev-contain-init)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system REQUIRED)

add_executable(dev_contain_init
  src/dev-contain-init.cpp)
target_include_directories(dev_contain_init
  PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(dev_contain_init
  -static
  ${Boost_SYSTEM_LIBRARY})
target_compile_options(dev_contain_init
  PUBLIC -Wall -Wextra)
