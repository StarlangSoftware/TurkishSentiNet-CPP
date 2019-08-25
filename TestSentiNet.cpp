//
// Created by Olcay Taner YILDIZ on 2019-08-25.
//

#include <vector>
#include "SentiNet.h"

int main(){
    SentiNet sentiNet = SentiNet();
    vector<string> p = sentiNet.getPositives();
    vector<string> n = sentiNet.getNegatives();
    vector<string> nt = sentiNet.getNeutrals();
}