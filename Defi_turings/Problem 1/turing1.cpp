/* Problem statement : Si on liste tous les entiers naturels inferieurs a 20 qui sont multiples de 5 ou de 7 on obtient, 5, 7, 10, 14 et 15. La somme de ces nombres est 51.
Trouver la somme de tous les multiples de 5 ou de 7 inferieurs a 2013 */

/* We just need to add all the multiples of 7 and the multiples of 5 then substract the intersection.  */

// With the property : given an integer N, for integer i, N*i is a multiple of N.
// We deduce the sum from i=1 to a certain integer MAX of N*i equal N*MAX*(MAX+1)/2
// Similarly, having all the common multiples of 7 and 5 being multiples of their Least Common Multiple:: 35
// We remove these multiples from the sum

// In this question, the integer MAX is implicitly defined such the N*MAX <= 2013
// Hence MAX is the integer part of (2013/N)


#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int NUMBER = 2013;
    int max5= NUMBER/5; int max7= NUMBER/7; int max35= NUMBER/35;
    int sum = (5*(max5*(max5+1)) + 7*(max7*(max7+1)) - 35*(max35*(max35+1)))/2;
    cout << "Problem 1: " << sum << endl;
    return 0;
}