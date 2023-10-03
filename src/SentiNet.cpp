//
// Created by Olcay Taner YILDIZ on 2019-08-25.
//

#include "SentiNet.h"
#include "XmlDocument.h"

void SentiNet::loadSentiNet(const string& fileName) {
    XmlElement *rootNode, *sentiSynSetNode, *partNode;
    string id;
    double positiveScore = 0.0, negativeScore = 0.0;
    XmlDocument doc = XmlDocument(fileName);
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
            sentiSynSetList.emplace(id, new SentiSynSet(id, positiveScore, negativeScore));
        }
        sentiSynSetNode = sentiSynSetNode->getNextSibling();
        id = "";
        positiveScore = 0.0;
        negativeScore = 0.0;
    }
}

/**
 * Constructor of Turkish SentiNet. Reads the turkish_sentinet.xml file. For each
 * sentiSynSet read, it adds it to the sentiSynSetList.
 */
SentiNet::SentiNet() {
    loadSentiNet("turkish_sentinet.xml");
}

/**
 * Constructor of Turkish SentiNet. Reads the file with name fileName. For each
 * sentiSynSet read, it adds it to the sentiSynSetList.
 */
SentiNet::SentiNet(const string& fileName) {
    loadSentiNet(fileName);
}

/**
 * Accessor for a single SentiSynSet.
 * @param id Id of the searched SentiSynSet.
 * @return SentiSynSet with the given id.
 */
SentiSynSet* SentiNet::getSentiSynSet(const string& id) const{
    if (sentiSynSetList.contains(id)){
        return sentiSynSetList.find(id)->second;
    } else {
        return nullptr;
    }
}

/**
 * Constructs and returns an vector of ids, which are the ids of the SentiSynSets having polarity
 * polarityType.
 * @param polarityType PolarityTypes of the searched SentiSynSets
 * @return A vector of id having polarityType polarityType.
 */
vector<string> SentiNet::getPolarity(PolarityType polarityType) const{
    vector<string> result;
    for (auto& iterator : sentiSynSetList){
        if (iterator.second->getPolarity() == polarityType){
            result.emplace_back(iterator.first);
        }
    }
    return result;
}

/**
 * Returns the ids of all positive SentiSynSets.
 * @return A vector of ids of all positive SentiSynSets.
 */
vector<string> SentiNet::getPositives() const{
    return getPolarity(PolarityType::POSITIVE);
}

/**
 * Returns the ids of all negative SentiSynSets.
 * @return A vector of ids of all negative SentiSynSets.
 */
vector<string> SentiNet::getNegatives() const{
    return getPolarity(PolarityType::NEGATIVE);
}

/**
 * Returns the ids of all neutral SentiSynSets.
 * @return A vector of ids of all neutral SentiSynSets.
 */
vector<string> SentiNet::getNeutrals() const{
    return getPolarity(PolarityType::NEUTRAL);
}

/**
 * Method to write SentiSynsets to the specified file in the XML format.
 *
 * @param fileName file name to write XML files
 */
void SentiNet::saveAsXml(const string& fileName) {
    ofstream outFile;
    outFile.open(fileName, ofstream::out);
    outFile << "<SYNSETS>\n";
    for (auto& iterator : sentiSynSetList){
        iterator.second->saveAsXml(outFile);
    }
    outFile << "</SYNSETS>\n";
    outFile.close();
}

/**
 * Removes specified SentiSynSet from the SentiSynSet list.
 *
 * @param sentiSynSet SentiSynSet to be added
 */
void SentiNet::removeSynSet(const SentiSynSet& sentiSynSet) {
    sentiSynSetList.erase(sentiSynSet.getId());
}

SentiNet::~SentiNet() {
    for (auto& iterator : sentiSynSetList){
        delete iterator.second;
    }
}
