cmake_minimum_required(VERSION 3.13)
project(SentiNet)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
link_directories(library)

add_library(SentiNet PolarityType.h SentiSynSet.cpp SentiSynSet.h SentiNet.cpp SentiNet.h SentiLiteral.cpp SentiLiteral.h SentiLiteralNet.cpp SentiLiteralNet.h)
add_executable(Test PolarityType.h SentiSynSet.cpp SentiSynSet.h SentiNet.cpp SentiNet.h Test/catch.hpp Test/SentiNetTest.cpp Test/SentiSynSetTest.cpp SentiLiteral.cpp SentiLiteral.h SentiLiteralNet.cpp SentiLiteralNet.h Test/SentiLiteralNetTest.cpp)

target_link_libraries(SentiNet XmlParser)
target_link_libraries(Test XmlParser)
