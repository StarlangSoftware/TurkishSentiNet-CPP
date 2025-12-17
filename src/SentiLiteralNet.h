//
// Created by Olcay Taner YILDIZ on 6.07.2021.
//

#ifndef SENTINET_SENTILITERALNET_H
#define SENTINET_SENTILITERALNET_H

#include <map>
#include <vector>

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
    [[nodiscard]] SentiLiteral* getSentiLiteral(const string& name) const;
    [[nodiscard]] vector<string> getPolarity(PolarityType polarityType) const;
    [[nodiscard]] vector<string> getPositives() const;
    [[nodiscard]] vector<string> getNegatives() const;
    [[nodiscard]] vector<string> getNeutrals() const;
};


#endif //SENTINET_SENTILITERALNET_H
