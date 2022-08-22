cmake_minimum_required(VERSION 3.13)

project(expathtml)

option (XML_STATIC "Use xml static" ON)

set(BUILD_SHARED_LIBS ON)

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
