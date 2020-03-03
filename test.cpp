#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "candy.h"
#include <algorithm>
using namespace std;

vector<candy*> myCandies;
string T = "";

//Read & parse & store the data
void setData(){
    std::ifstream file("../small.in");
    if (file.is_open()) {
        std::string count;
        std::string candies;
        getline(file,count);
        T = count;
        while (getline(file, count) && getline(file, candies)) {
            myCandies.push_back(new candy(stoi(count) ,candies));
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
