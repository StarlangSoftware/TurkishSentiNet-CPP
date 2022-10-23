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
    void loadSentiNet(const string& fileName);
public:
    SentiLiteralNet();
    ~SentiLiteralNet();
    explicit SentiLiteralNet(const string& fileName);
    SentiLiteral* getSentiLiteral(const string& name) const;
    vector<string> getPolarity(PolarityType polarityType) const;
    vector<string> getPositives() const;
    vector<string> getNegatives() const;
    vector<string> getNeutrals() const;
};


#endif //SENTINET_SENTILITERALNET_H
