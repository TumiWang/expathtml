cmake_minimum_required(VERSION 3.13)

project(expathtml)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_SHARED_LIBS OFF)

set(HTML_SOURCE
    src/xmlparse.c
    src/xmlrole.c
    src/xmltok.c
    )

add_library(expathtml ${HTML_SOURCE})

target_include_directories(expathtml PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
                           )

target_include_directories(expathtml PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}/inc
                           )

set(TEST_SOURCE
    test/main.cpp)

add_executable(test ${TEST_SOURCE})

target_include_directories(test PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
                           )

target_link_libraries(test PRIVATE expathtml)
