//
// Created by Olcay Taner YILDIZ on 2019-08-25.
//

#ifndef SENTINET_SENTINET_H
#define SENTINET_SENTINET_H

#include <map>
#include <vector>

#include "SentiSynSet.h"

using namespace std;

class SentiNet {
private:
    map<string, SentiSynSet*> sentiSynSetList;
    void loadSentiNet(const string& fileName);
public:
    SentiNet();
    ~SentiNet();
    explicit SentiNet(const string& fileName);
    [[nodiscard]] SentiSynSet* getSentiSynSet(const string& id) const;
    [[nodiscard]] vector<string> getPolarity(PolarityType polarityType) const;
    [[nodiscard]] vector<string> getPositives() const;
    [[nodiscard]] vector<string> getNegatives() const;
    [[nodiscard]] vector<string> getNeutrals() const;
    void removeSynSet(const SentiSynSet& s);
    void saveAsXml(const string& fileName) const;
};


#endif //SENTINET_SENTINET_H
