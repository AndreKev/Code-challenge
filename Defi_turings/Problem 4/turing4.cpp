// Problem Statemen

// Analysis

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    bool found = 0; int number; int MAX = 9999*999;
    for (int h=9; (h>-1)&&(!found); h--){
        for (int i=9; (i>-1)&&(!found); i--){
            for (int j=9; (j>-1)&&(!found); j--){
                for (int k=9; (k>-1)&&(!found); k--){
                    number = h*pow(10,6) + i*pow(10,5) + j*pow(10,4) + k*pow(10, 3) + j*pow(10,2) + i*pow(10,1) + h;
                    for (int root = pow(number, 0.5); root>1000; root--){
                        //cout << number << " " << root << " " << number/root << endl;
                        if (number>MAX) break;
                        if (number%root==0){
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << "Problem 4 : " << number << endl;
}