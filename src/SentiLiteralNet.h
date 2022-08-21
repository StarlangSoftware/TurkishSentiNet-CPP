//
// Created by Olcay Taner YILDIZ on 6.07.2021.
//

#ifndef SENTINET_SENTILITERALNET_H
#define SENTINET_SENTILITERALNET_H

#include <map>
#include "SentiLiteral.h"

using namespace std;

class SentiLiteralNet {
private:
    map<string, SentiLiteral*> sentiLiteralList;
    void loadSentiNet(string fileName);
public:
    SentiLiteralNet();
    ~SentiLiteralNet();
    explicit SentiLiteralNet(string fileName);
    SentiLiteral* getSentiLiteral(string name);
    vector<string> getPolarity(PolarityType polarityType);
    vector<string> getPositives();
    vector<string> getNegatives();
    vector<string> getNeutrals();
};


#endif //SENTINET_SENTILITERALNET_H
