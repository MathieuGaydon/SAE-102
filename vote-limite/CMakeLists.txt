cmake_minimum_required(VERSION 3.16)

project(vote-limite LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vote-limite main.cpp)

include(GNUInstallDirs)
install(TARGETS vote-limite
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
