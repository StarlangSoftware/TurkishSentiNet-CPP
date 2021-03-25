//
// Created by Olcay Taner YILDIZ on 19.12.2020.
//

#include <fstream>
#include "catch.hpp"
#include "../SentiNet.h"

TEST_CASE("SentiSynSet-saveAsXml") {
    string line;
    ifstream infile;
    ofstream outFile;
    SentiNet sentiNet = SentiNet();
    outFile.open("test.xml", ofstream::out);
    SentiSynSet* sentiSynSet = sentiNet.getSentiSynSet("TUR10-1093230");
    sentiSynSet->saveAsXml(outFile);
    sentiSynSet = sentiNet.getSentiSynSet("TUR10-0730690");
    sentiSynSet->saveAsXml(outFile);
    sentiSynSet = sentiNet.getSentiSynSet("TUR10-0969360");
    sentiSynSet->saveAsXml(outFile);
    outFile.close();
    infile.open("test.xml", ifstream::in);
    getline(infile, line);
    REQUIRE("<SYNSET><ID>TUR10-1093230</ID><PSCORE>0.25</PSCORE><NSCORE>0</NSCORE></SYNSET>" == line);
    getline(infile, line);
    REQUIRE("<SYNSET><ID>TUR10-0730690</ID><PSCORE>0</PSCORE><NSCORE>0</NSCORE></SYNSET>" == line);
    getline(infile, line);
    REQUIRE("<SYNSET><ID>TUR10-0969360</ID><PSCORE>0</PSCORE><NSCORE>1</NSCORE></SYNSET>" == line);
    infile.close();
}
