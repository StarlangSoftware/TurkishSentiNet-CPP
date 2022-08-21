//
// Created by Olcay Taner YILDIZ on 19.12.2020.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/SentiNet.h"

TEST_CASE("SentiNet-getPositives") {
    SentiNet sentiNet = SentiNet();
    REQUIRE(3100 == sentiNet.getPositives().size());
}

TEST_CASE("SentiNet-getNegatives") {
    SentiNet sentiNet = SentiNet();
    REQUIRE(10191 == sentiNet.getNegatives().size());
}

TEST_CASE("SentiNet-getNeutrals") {
    SentiNet sentiNet = SentiNet();
    REQUIRE(63534 == sentiNet.getNeutrals().size());
}
