cmake_minimum_required(VERSION 2.8)
project(cpakt)

set(CPAKT_SOURCE_FILES
    include/cpakt/cpakt-asserts.h
    include/cpakt/cpakt-assertz.h
    include/cpakt/cpakt-defs.h
    include/cpakt/cpakt-impl.h
    include/cpakt/cpakt-magic.h
    include/cpakt/cpakt-main.h
    src/cpakt.c)

include_directories(include)
add_library(cpakt_static STATIC ${CPAKT_SOURCE_FILES})
add_library(cpakt_shared SHARED ${CPAKT_SOURCE_FILES})
