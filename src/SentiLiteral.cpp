//
// Created by Olcay Taner YILDIZ on 6.07.2021.
//

#include "SentiLiteral.h"

/**
 * Constructor of SentiLiteral. Gets input id, positiveScore, negativeScore and sets all corresponding attributes.
 * @param _name Name of the SentiLiteral.
 * @param positiveScore Positive score of the SentiLiteral.
 * @param negativeScore Negative score of the SentiLiteral.
 */
SentiLiteral::SentiLiteral(const string& _name, double positiveScore, double negativeScore) {
    this->name = _name;
    this->positiveScore = positiveScore;
    this->negativeScore = negativeScore;
}

/**
 * Accessor for the positiveScore attribute.
 * @return PositiveScore of the SentiLiteral.
 */
double SentiLiteral::getPositiveScore() {
    return positiveScore;
}

/**
 * Accessor for the negativeScore attribute.
 * @return NegativeScore of the SentiLiteral.
 */
double SentiLiteral::getNegativeScore() {
    return negativeScore;
}

/**
 * Returns the polarityType of the SentiLiteral. If the positive score is larger than the negative score, the polarity is
 * positive; if the negative score is larger than the positive score, the polarity is negative; if both positive
 * score and negative score are equal, the polarity is neutral.
 * @return PolarityType of the SentiLiteral.
 */
PolarityType SentiLiteral::getPolarity() {
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
 * @return Id of the SentiLiteral.
 */
string SentiLiteral::getName() {
    return name;
}
