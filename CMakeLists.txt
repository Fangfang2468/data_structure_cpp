cmake_minimum_required(VERSION 3.30)
project(acm_study)

# 设置C++标准
set(CMAKE_CXX_STANDARD 23)

aux_source_directory(./1.Recursion Recursion)
add_executable(Recursion ${Recursion})

aux_source_directory(./2.Tree Tree)
add_executable(Tree ${Tree})

# 链接Cocoa框架
target_link_libraries(Recursion)