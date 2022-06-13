cmake_minimum_required(VERSION 3.16)

project(changetext)

add_library(
    ${PROJECT_NAME} SHARED
    sources/changetext.c
)

# include_directories(/usr/include/python3.8)
