cmake_minimum_required(VERSION 3.16)

project(vote-majoritaire-deux-tours LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vote-majoritaire-deux-tours main.cpp)

include(GNUInstallDirs)
install(TARGETS vote-majoritaire-deux-tours
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
