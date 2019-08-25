cmake_minimum_required(VERSION 3.13)
project(SentiNet)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
link_directories(library)

add_library(SentiNet PolarityType.h SentiSynSet.cpp SentiSynSet.h SentiNet.cpp SentiNet.h)
add_executable(TestSentiNet PolarityType.h SentiSynSet.cpp SentiSynSet.h SentiNet.cpp SentiNet.h TestSentiNet.cpp)

target_link_libraries(SentiNet XmlParser)
target_link_libraries(TestSentiNet XmlParser)
