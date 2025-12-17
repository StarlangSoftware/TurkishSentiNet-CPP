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
    SentiLiteral(const string& _name, double positiveScore, double negativeScore);
    [[nodiscard]] double getPositiveScore() const;
    [[nodiscard]] double getNegativeScore() const;
    [[nodiscard]] string getName() const;
    [[nodiscard]] PolarityType getPolarity() const;
};


#endif //SENTINET_SENTILITERAL_H
