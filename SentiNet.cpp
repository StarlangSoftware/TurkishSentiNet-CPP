//
// Created by Olcay Taner YILDIZ on 2019-08-25.
//

#include "SentiNet.h"
#include "XmlDocument.h"

/**
 * Constructor of Turkish SentiNet. Reads the turkish_sentinet.xml file from the resources directory. For each
 * sentiSynSet read, it adds it to the sentiSynSetList.
 */
SentiNet::SentiNet() {
    XmlElement *rootNode, *sentiSynSetNode, *partNode;
    string id;
    double positiveScore = 0.0, negativeScore = 0.0;
    XmlDocument doc = XmlDocument("turkish_sentinet.xml");
    doc.parse();
    rootNode = doc.getFirstChild();
    sentiSynSetNode = rootNode->getFirstChild();
    while (sentiSynSetNode != nullptr){
        partNode = sentiSynSetNode->getFirstChild();
        while (partNode != nullptr){
            if (partNode->getName() == "ID"){
                id = partNode->getPcData();
            } else {
                if (partNode->getName() == "PSCORE"){
                    positiveScore = stof(partNode->getPcData());
                } else {
                    if (partNode->getName() == "NSCORE"){
                        negativeScore = stof(partNode->getPcData());
                    }
                }
            }
            partNode = partNode->getNextSibling();
        }
        if (!id.empty()){
            sentiSynSetList.emplace(id, SentiSynSet(id, positiveScore, negativeScore));
        }
        sentiSynSetNode = sentiSynSetNode->getNextSibling();
        id = "";
        positiveScore = 0.0;
        negativeScore = 0.0;
    }
}

/**
 * Accessor for a single SentiSynSet.
 * @param id Id of the searched SentiSynSet.
 * @return SentiSynSet with the given id.
 */
SentiSynSet SentiNet::getSentiSynSet(string id) {
    return sentiSynSetList.find(id)->second;
}

/**
 * Constructs and returns an {@link vector} of ids, which are the ids of the {@link SentiSynSet}s having polarity
 * polarityType.
 * @param polarityType PolarityTypes of the searched {@link SentiSynSet}s
 * @return A {@link vector} of id having polarityType polarityType.
 */
vector<string> SentiNet::getPolarity(PolarityType polarityType) {
    vector<string> result;
    for (auto& iterator : sentiSynSetList){
        if (iterator.second.getPolarity() == polarityType){
            result.emplace_back(iterator.first);
        }
    }
    return result;
}

/**
 * Returns the ids of all positive {@link SentiSynSet}s.
 * @return A {@link vector} of ids of all positive {@link SentiSynSet}s.
 */
vector<string> SentiNet::getPositives() {
    return getPolarity(PolarityType::POSITIVE);
}

/**
 * Returns the ids of all negative {@link SentiSynSet}s.
 * @return A {@link vector} of ids of all negative {@link SentiSynSet}s.
 */
vector<string> SentiNet::getNegatives() {
    return getPolarity(PolarityType::NEGATIVE);
}

/**
 * Returns the ids of all neutral {@link SentiSynSet}s.
 * @return A {@link vector} of ids of all neutral {@link SentiSynSet}s.
 */
vector<string> SentiNet::getNeutrals() {
    return getPolarity(PolarityType::NEUTRAL);
}
