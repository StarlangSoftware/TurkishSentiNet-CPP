cmake_minimum_required(VERSION 3.13)
project(SentiNet)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(xml_parser REQUIRED)

add_library(SentiNet PolarityType.h SentiSynSet.cpp SentiSynSet.h SentiNet.cpp SentiNet.h SentiLiteral.cpp SentiLiteral.h SentiLiteralNet.cpp SentiLiteralNet.h)
target_link_libraries(SentiNet xml_parser::xml_parser)
