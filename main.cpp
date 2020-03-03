#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "candy.h"
#include <algorithm>
using namespace std;

vector<candy*> myCandies;
string T = "";
void setData(){
    std::ifstream file("../small.in");
    if (file.is_open()) {
        std::string line;
        std::string line1;
        getline(file,line);
        T = line;
        while (getline(file, line) && getline(file, line1)) {
            myCandies.push_back(new candy(stoi(line) ,line1));
        }
        file.close();
    }
}

int petrickSum(vector<double> parts){
    int sum=0;
    for(int n:parts){
        sum^=n;
    }
    return sum;
}

void output(){
    int caseTest = 1;
    for(candy *c:myCandies){
        int petrickSumRes = petrickSum(c->getParts());
        if(petrickSumRes!=0){
            cout<<"Case #"<<caseTest<<": "<<"NO"<<endl;
        }
        else{
            double minimum = LONG_MAX;
            int sum=0;
            for(double n:c->getParts()){
                sum+=n;
                minimum = std::min(minimum,n);
            }
            cout<<"Case #"<<caseTest<<": "<<sum-minimum<<endl;
        }
        caseTest++;
    }

}

int main(int argc, char *argv[]) {
    setData();
    output();
    return 0;
}
