// Statement 
/*
    Let's consider a^b for 2<=a<=5, 2<=b<=5.
    If we sort the seires of 
*/

#include <iostream>

using namespace std;

long long pow(long, long);

int main(){
    int argv[] = {16, 8};
    for (int j=2; j<=argv[1]; j++) 
        cout << "\t" << j;
    cout << endl;
    for (int j=2; j<=argv[1]; j++) 
        cout << "\t-";
    cout << endl;
    for (int i=2; i<=argv[0]; i++){
        cout << i << ":";
        for (int j=2; j<=argv[1]; j++)
            cout << "\t" << pow(i, j);
        cout << endl;
    }
}

long long pow(long i, long j){
    long long output = i;
    for (int k=2; k<=j; k++)
        output *= i;
    return output;
}