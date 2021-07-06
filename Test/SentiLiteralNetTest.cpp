//
// Created by Olcay Taner YILDIZ on 6.07.2021.
//

#include "catch.hpp"
#include "../SentiLiteralNet.h"

TEST_CASE("SentiLiteralNet-getPositives") {
    SentiLiteralNet sentiNet = SentiLiteralNet();
    REQUIRE(4335 == sentiNet.getPositives().size());
}

TEST_CASE("SentiLiteralNet-getNegatives") {
    SentiLiteralNet sentiNet = SentiLiteralNet();
    REQUIRE(13011 == sentiNet.getNegatives().size());
}

TEST_CASE("SentiLiteralNet-getNeutrals") {
    SentiLiteralNet sentiNet = SentiLiteralNet();
    REQUIRE(62379 == sentiNet.getNeutrals().size());
}
