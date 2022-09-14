#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define INDEXPERMUTATION 2000000
using namespace std;

ostream& operator<<(ostream& outstream, vector<int> vec){
    for (auto element: vec)
        outstream << element;
    return outstream;
}

int main(){
    vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
    int numbers=1;
    do {
        next_permutation(digits.begin(), digits.end());
        //print(digits);
        numbers++;
    } while (numbers!=INDEXPERMUTATION);
    cout << "Problem 24: " << digits << endl;
}