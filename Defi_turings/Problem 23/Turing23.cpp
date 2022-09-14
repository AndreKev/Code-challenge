#include <iostream>
#include <bits/stdc++.h>

#define ull unsigned long long
using namespace std;

unsigned long long factorial(unsigned int);

int main(){
    int m = 30; // Length
    int n = 20; // Width
    ull result=1;
    // auxiliary variables
    int limit = (m<n)? n-1: m-1;
    for (int k = m+n; k>limit; k--)
        result *= k;
    for (int j = m+n-limit; j>2; j--)
        result /= j;
    cout << "Problem 23: " << factorial(30) << endl;
}

ull factorial(unsigned int number){
    if (number==0)
        return 1;
    else
        return (ull) number*factorial(number-1);
}