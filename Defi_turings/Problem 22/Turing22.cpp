#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> digits(int);
bool equal(vector<int>, vector<int>);

int main(){
    int sum=0;
    int MAX = 999999/8;
    vector<int> first, second;
    for (int i=100000; i<MAX; i++){
        first = digits(i);
        second = digits(i*8);
        if (equal(first, second))
            {
                // If sum is not zero, then the actual element is the second one to be added. 
                // Hence we can break
                if (sum!=0) 
                    MAX=i;  // this will break the loop
                sum += i;
            }
    }
    cout << "Problem 22: " << sum << endl;
}

vector<int> digits(int number){
    vector<int> output;
    while (number){
        output.push_back(number%10);
        number/=10;
    }
    return output;
}

bool equal(vector<int> first, vector<int> second){
    sort(first.begin(), first.end());   // Sort the first vector
    sort(second.begin(), second.end()); // sort the second vector

    if (first.size()!=second.size())
        return false;
    else {
        int size = first.size();
        for (int i=0; i<size; i++){
            if (first[i]!=second[i])
                return false;
        }
        return true;
    }
}