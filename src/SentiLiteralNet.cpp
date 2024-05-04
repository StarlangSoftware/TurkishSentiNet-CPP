//
// Created by Olcay Taner YILDIZ on 6.07.2021.
//

#include "SentiLiteralNet.h"
#include "XmlDocument.h"

/**
 * Reads the Xml file that contains names of sentiLiterals and their positive, negative scores.
 * @param fileName Xml document that contains the SentiLiteralNet.
 */
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
SentiLiteral* SentiLiteralNet::getSentiLiteral(const string& name) const{
    if (sentiLiteralList.contains(name)){
        return sentiLiteralList.find(name)->second;
    } else {
        return nullptr;
    }
}

/**
 * Constructs and returns an vector of ids, which are the ids of the SentiLiterals having polarity
 * polarityType.
 * @param polarityType PolarityTypes of the searched SentiLiterals
 * @return A vector of id having polarityType polarityType.
 */
vector<string> SentiLiteralNet::getPolarity(PolarityType polarityType) const{
    vector<string> result;
    for (auto& iterator : sentiLiteralList){
        if (iterator.second->getPolarity() == polarityType){
            result.emplace_back(iterator.first);
        }
    }
    return result;
}

/**
 * Returns the ids of all positive SentiLiterals.
 * @return A vector of ids of all positive SentiLiterals.
 */
vector<string> SentiLiteralNet::getPositives() const{
    return getPolarity(PolarityType::POSITIVE);
}

/**
 * Returns the ids of all negative SentiLiterals.
 * @return A vector of ids of all negative SentiLiterals.
 */
vector<string> SentiLiteralNet::getNegatives() const{
    return getPolarity(PolarityType::NEGATIVE);
}

/**
 * Returns the ids of all neutral SentiLiterals.
 * @return A vector of ids of all neutral SentiLiterals.
 */
vector<string> SentiLiteralNet::getNeutrals() const{
    return getPolarity(PolarityType::NEUTRAL);
}

SentiLiteralNet::~SentiLiteralNet() {
    for (auto& iterator : sentiLiteralList){
        delete iterator.second;
    }
}
