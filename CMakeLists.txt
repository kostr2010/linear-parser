
cmake_minimum_required(VERSION 3.10)
project(linear-parser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -g")

add_executable(example example.cpp)

add_executable(parse_operands_gen parse_operands_gen.cpp)

add_library(parser SHARED parser.cpp lexer.cpp instruction.cpp parse_operands.cpp)

add_custom_command(OUTPUT parse_operands.cpp
                  COMMAND ${CMAKE_BINARY_DIR}/parse_operands_gen
                  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
                  DEPENDS parse_operands_gen)

# add_dependencies(parser parse_operands.cpp)

target_link_libraries(example parser)

target_include_directories(parser PUBLIC ${CMAKE_SOURCE_DIR})

