//
// Created by Olcay Taner YILDIZ on 6.07.2021.
//

#ifndef SENTINET_SENTILITERAL_H
#define SENTINET_SENTILITERAL_H

#include <string>
#include "PolarityType.h"

using namespace std;

class SentiLiteral {
private:
    string name;
    double positiveScore;
    double negativeScore;
public:
    SentiLiteral(string name, double positiveScore, double negativeScore);
    double getPositiveScore();
    double getNegativeScore();
    string getName();
    PolarityType getPolarity();
};


#endif //SENTINET_SENTILITERAL_H
