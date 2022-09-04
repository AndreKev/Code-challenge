// Problem Statement
/* Chaque nouveau termen de la suite de Fibonacci est la somme des 
deux termes precedents. Quelle est la somme des termes impairs de la suite 
ne depassant pas 4000000 ? */

// Analysis
// The fibonacci series, with first terms 0 and 1 is [ 0, 1, 1, 2, 3, 5, 8, ...
// Sampling the series into a set of ordered and disjoint triples (a,b,c):: [ (0,1,1), (2,3,5), (8,..)]
// we notice a is the only even number.
// Hence we can build the series and only add "b"s and "c"s to the sum.

#include <iostream>
using namespace std;

int main(){
    int a=0, b=1, c=a+b;
    int sum=0;
    while (c<4000000){
        //cout << a << " " << b << " " << c << " \n";
        sum += b+c;
        a = b+c;
        b = a+c;
        c = a+b;
    }
    if ((c>4000000)&&(b<4000000)) {
        //cout << a << " b" << b << " " << c << endl;
        sum+= b;
    }
    cout << "Problem 2: " << sum << endl;
}