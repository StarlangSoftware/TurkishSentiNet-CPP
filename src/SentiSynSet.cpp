#include <utility>

//
// Created by Olcay Taner YILDIZ on 2019-08-25.
//

#include "SentiSynSet.h"
#include <fstream>

/**
 * Constructor of SentiSynSet. Gets input _id, positiveScore, negativeScore and sets all corresponding attributes.
 * @param _id Id of the SentiSynSet.
 * @param positiveScore Positive score of the SentiSynSet.
 * @param negativeScore Negative score of the SentiSynSet.
 */
SentiSynSet::SentiSynSet(const string& _id, double positiveScore, double negativeScore) {
    this->id = _id;
    this->positiveScore = positiveScore;
    this->negativeScore = negativeScore;
}

/**
 * Accessor for the positiveScore attribute.
 * @return PositiveScore of the SentiSynSet.
 */
double SentiSynSet::getPositiveScore() const{
    return positiveScore;
}

/**
 * Accessor for the negativeScore attribute.
 * @return NegativeScore of the SentiSynSet.
 */
double SentiSynSet::getNegativeScore() const{
    return negativeScore;
}

/**
 * Returns the polarityType of the sentiSynSet. If the positive score is larger than the negative score, the polarity is
 * positive; if the negative score is larger than the positive score, the polarity is negative; if both positive
 * score and negative score are equal, the polarity is neutral.
 * @return PolarityType of the sentiSynSet.
 */
PolarityType SentiSynSet::getPolarity() const{
    if (positiveScore > negativeScore){
        return PolarityType::POSITIVE;
    } else {
        if (positiveScore < negativeScore){
            return PolarityType::NEGATIVE;
        } else {
            return PolarityType::NEUTRAL;
        }
    }
}

/**
 * Accessor for the id attribute.
 * @return Id of the SentiSynSet.
 */
string SentiSynSet::getId() const{
    return id;
}

/**
 * Method to write SentiSynSets to the specified file in the XML format.
 *
 * @param outfile BufferedWriter to write XML files
 */
void SentiSynSet::saveAsXml(ofstream &outfile) {
    outfile << "<SYNSET>";
    outfile << "<ID>" + id + "</ID>";
    outfile << "<PSCORE>" << positiveScore << "</PSCORE>";
    outfile << "<NSCORE>" << negativeScore << "</NSCORE>";
    outfile << "</SYNSET>\n";
}
