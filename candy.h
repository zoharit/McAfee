//
// Created by user on 03/03/2020.
//

#ifndef MCAFEECHALLENGE_CANDY_H
#define MCAFEECHALLENGE_CANDY_H

#include <vector>
#include <string>

using namespace std;

class candy {
private:
    int N;
    vector<double> candyParts;

public:
    candy(int N, string s);
    vector<double> getParts();
    int getN();
};


#endif //MCAFEECHALLENGE_CANDY_H
