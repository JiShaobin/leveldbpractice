# 设置最低CMake版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(levelDBPractice)

# 添加 leveldb 子目录以构建 leveldb 库
add_subdirectory(leveldb)

# 包含 leveldb 库的头文件
set(LEVELDB_PUBLIC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/leveldb/include)
include_directories(${LEVELDB_PUBLIC_INCLUDE_DIR})

# 添加你的可执行文件
add_executable(leveldbpractice main.cpp)

# 链接 leveldb 库
target_link_libraries(leveldbpractice leveldb)
