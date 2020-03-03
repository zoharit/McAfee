//
// Created by user on 03/03/2020.
//

#include "candy.h"
#include <iostream>     // std::cout
#include <sstream>
candy::candy(int N, string s) {
    this->N = N;
    std::istringstream iss(s);
    for (double s; iss >> s;)
        this->candyParts.push_back(s);

}
vector<double> candy::getParts(){
    return this->candyParts;
}
int candy::getN(){
    return this->N;
}

