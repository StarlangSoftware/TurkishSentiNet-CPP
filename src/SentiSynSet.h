//
// Created by Olcay Taner YILDIZ on 2019-08-25.
//

#ifndef SENTINET_SENTISYNSET_H
#define SENTINET_SENTISYNSET_H

#include <string>
#include "PolarityType.h"

using namespace std;

class SentiSynSet {
private:
    string id;
    double positiveScore;
    double negativeScore;
public:
    SentiSynSet(const string& _id, double positiveScore, double negativeScore);
    double getPositiveScore();
    double getNegativeScore();
    string getId() const;
    PolarityType getPolarity();
    void saveAsXml(ofstream& outfile);
};


#endif //SENTINET_SENTISYNSET_H
