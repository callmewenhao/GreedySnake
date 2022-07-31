cmake_minimum_required(VERSION 3.22)
project(GreedySnake)

set(CMAKE_CXX_STANDARD 14)

set(EasyX_INC D:\\EasyX\\include) # 你的include地址
set(EasyX_LINK D:\\EasyX\\lib\\VC2015\\x64) # 找与自己的环境配置对应的版本
include_directories(${EasyX_INC})
link_directories(${EasyX_LINK})

#在lib对应的文件夹里面找lib文件（一般只有EasyXa和EasyXw这两个，进行链接）
link_libraries(EasyXa)
link_libraries(EasyXw)

add_executable(GreedySnake main.cpp snake/Body.cpp snake/Body.h snake/Head.cpp snake/Head.h Game.cpp Game.h snake/Snake.cpp snake/Snake.h Food.cpp Food.h)
