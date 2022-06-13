cmake_minimum_required(VERSION 3.16)

project(changetext)

add_library(
    ${PROJECT_NAME} SHARED
    sources/changetext.c
    sources/changetext.h
)

target_include_directories(changetext PRIVATE /usr/include/python3.8)

# add_executable(
#     test
#     sources/test.cpp
# )

# set_property(TARGET test PROPERTY CXX_STANDARD 11)

# target_link_libraries(test
#     PRIVATE
#         ${PROJECT_NAME}
# )
