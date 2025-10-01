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
    SentiSynSet* getSentiSynSet(const string& id) const;
    vector<string> getPolarity(PolarityType polarityType) const;
    vector<string> getPositives() const;
    vector<string> getNegatives() const;
    vector<string> getNeutrals() const;
    void removeSynSet(const SentiSynSet& s);
    void saveAsXml(const string& fileName) const;
};


#endif //SENTINET_SENTINET_H
