cmake_minimum_required(VERSION 3.13)
project(SentiNet)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(SentiNet src/PolarityType.h src/SentiSynSet.cpp src/SentiSynSet.h src/SentiNet.cpp src/SentiNet.h src/SentiLiteral.cpp src/SentiLiteral.h src/SentiLiteralNet.cpp src/SentiLiteralNet.h)
add_executable(Test src/PolarityType.h src/SentiSynSet.cpp src/SentiSynSet.h src/SentiNet.cpp src/SentiNet.h Test/catch.hpp Test/SentiNetTest.cpp Test/SentiSynSetTest.cpp src/SentiLiteral.cpp src/SentiLiteral.h src/SentiLiteralNet.cpp src/SentiLiteralNet.h Test/SentiLiteralNetTest.cpp)
target_link_libraries(SentiNet ${CONAN_LIBS})
target_link_libraries(Test ${CONAN_LIBS})
