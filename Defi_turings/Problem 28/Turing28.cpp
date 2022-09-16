#include <iostream>
#define MAXGRIDSIZE 2013
using namespace std;

int main(){
    long element = 1;
    long long sum = element;
    for (int i=3; i<=MAXGRIDSIZE; i+=2){
            sum += 4*element+10*(i-1);
            element += (i-1)*4;
    }
    cout << "Problem 28: " << sum << endl;
}