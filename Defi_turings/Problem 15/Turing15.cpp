// Problem Statement

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// Transform the digits to get the final number
int apply(vector<int>);
void print(vector<int> digits){
    for (int i=0; i<digits.size(); i++) cout << digits[i] << " ";
    cout << endl;
}

int main(){
    vector<int> digits;
    for (int i=1; i<10; i++) 
        digits.push_back(i);    // Placing digits 0,1,2...9 in the vector
    int max = (int)-INFINITY;  // Max value
    int min = (int)INFINITY;  // Min value
    int aux;
    do {
        aux = apply(digits);
        // Replacing by the actual min and max
        if (aux>max) max = aux;
        if (aux<min) min = aux;
    } while (next_permutation(digits.begin(), digits.end())); // This function permuts my vector

    cout << "Problem 15: " << (long long) (max*min) << endl;
    return 0;
}

int apply(vector<int> digits){
    // A lambda expression
    auto apply_min = [](int a, int b, int c, int d, int e, vector<int> digits){
        return digits[c]*(digits[a]*digits[b]+digits[d]*digits[e]);
    };
    return apply_min(2, 1, 0, 3, 6, digits) + apply_min(3, 5, 4, 1, 7, digits) + apply_min(6, 7, 8, 2, 5, digits);
}