# 声明要求的 cmake 最低版本
cmake_minimum_required( VERSION 3.8 )

# 声明一个 cmake 工程
project( buff )

set(CMAKE_CXX_STANDARD 11)
# 设置编译模式为Debug模式
set( CMAKE_BUILD_TYPE "Debug" )

#INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/3drpart/)

#Depend(buff git "https://github.com/zntx/buff.git" )

# aux_source_directory(src SOURCES)


# # 生成一个静态库，会生成一个libhello.a文件
# add_library( ${PROJECT_NAME} STATIC ${SOURCES} )

# 生成一个静态库，会生成一个libhello.a文件
#add_library( ${PROJECT_NAME} STATIC ${SOURCES} )
# 生成一个共享库，会生成一个libhello_shared.so文件
#add_library( ${CMAKE_PROJECT_NAME} SHARED ${SOURCES} )

# 生成可执行文件useHello
#add_executable( useHello useHello.cpp )

# 将可执行程序链接到上库文件
#target_link_libraries( useHello hello_shared )