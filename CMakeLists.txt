cmake_minimum_required(VERSION 3.12)
project(Json_Demo)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "-static -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread")

include_directories("chilkat/include")
set(Chilkat_Lib ${CMAKE_SOURCE_DIR}/chilkat/libchilkat-9.5.0.a)

add_executable(Json_Demo main.cpp)
target_link_libraries(Json_Demo ${Chilkat_Lib} winmm.lib sapi wsock32 ws2_32 crypt32 ws2_32 gdiplus)
