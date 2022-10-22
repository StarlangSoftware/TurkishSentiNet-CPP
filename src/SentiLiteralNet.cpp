//
// Created by Olcay Taner YILDIZ on 6.07.2021.
//

#include "SentiLiteralNet.h"
#include "XmlDocument.h"

void SentiLiteralNet::loadSentiNet(const string& fileName) {
    XmlElement *rootNode, *sentiSynSetNode, *partNode;
    string name;
    double positiveScore = 0.0, negativeScore = 0.0;
    XmlDocument doc = XmlDocument(fileName);
    doc.parse();
    rootNode = doc.getFirstChild();
    sentiSynSetNode = rootNode->getFirstChild();
    while (sentiSynSetNode != nullptr){
        partNode = sentiSynSetNode->getFirstChild();
        while (partNode != nullptr){
            if (partNode->getName() == "NAME"){
                name = partNode->getPcData();
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
        if (!name.empty()){
            sentiLiteralList.emplace(name, new SentiLiteral(name, positiveScore, negativeScore));
        }
        sentiSynSetNode = sentiSynSetNode->getNextSibling();
        name = "";
        positiveScore = 0.0;
        negativeScore = 0.0;
    }
}

/**
 * Constructor of Turkish SentiNet. Reads the turkish_sentiliteralnet.xml file. For each
 * sentiSynSet read, it adds it to the sentiSynSetList.
 */
SentiLiteralNet::SentiLiteralNet() {
    loadSentiNet("turkish_sentiliteralnet.xml");
}

/**
 * Constructor of Turkish SentiNet. Reads the file with name fileName. For each
 * sentiLiteral read, it adds it to the sentiLiteralList.
 */
SentiLiteralNet::SentiLiteralNet(const string& fileName) {
    loadSentiNet(fileName);
}

/**
 * Accessor for a single SentiSynSet.
 * @param name Name of the searched SentiLiteral.
 * @return SentiSynSet with the given name.
 */
SentiLiteral* SentiLiteralNet::getSentiLiteral(const string& name) {
    if (sentiLiteralList.contains(name)){
        return sentiLiteralList.find(name)->second;
    } else {
        return nullptr;
    }
}

/**
 * Constructs and returns an {@link vector} of ids, which are the ids of the {@link SentiLiteral}s having polarity
 * polarityType.
 * @param polarityType PolarityTypes of the searched {@link SentiLiteral}s
 * @return A {@link vector} of id having polarityType polarityType.
 */
vector<string> SentiLiteralNet::getPolarity(PolarityType polarityType) {
    vector<string> result;
    for (auto& iterator : sentiLiteralList){
        if (iterator.second->getPolarity() == polarityType){
            result.emplace_back(iterator.first);
        }
    }
    return result;
}

/**
 * Returns the ids of all positive {@link SentiLiteral}s.
 * @return A {@link vector} of ids of all positive {@link SentiLiteral}s.
 */
vector<string> SentiLiteralNet::getPositives() {
    return getPolarity(PolarityType::POSITIVE);
}

/**
 * Returns the ids of all negative {@link SentiLiteral}s.
 * @return A {@link vector} of ids of all negative {@link SentiLiteral}s.
 */
vector<string> SentiLiteralNet::getNegatives() {
    return getPolarity(PolarityType::NEGATIVE);
}

/**
 * Returns the ids of all neutral {@link SentiLiteral}s.
 * @return A {@link vector} of ids of all neutral {@link SentiLiteral}s.
 */
vector<string> SentiLiteralNet::getNeutrals() {
    return getPolarity(PolarityType::NEUTRAL);
}

SentiLiteralNet::~SentiLiteralNet() {
    for (auto& iterator : sentiLiteralList){
        delete iterator.second;
    }
}
