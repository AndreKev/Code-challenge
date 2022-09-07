//  On the first one the period is 12,14 while on the second one the period is 10,12.
//  
//  if both start at 2, what is the intersection of the two sets in the interval 1, 2013

#include <iostream>
#include <map>

using namespace std;

int main(){
    int MAX = 2013 + 1;
    map<int, int> appeared;
    int hand1 = 2, hand2 = 2;

    int final_sum = 0;
    bool which = 1;
    while (hand2<MAX){
        appeared[hand1] = 1;
        if (appeared[hand2])
            final_sum += hand2;
        hand1 += (which)? 12: 2;
        hand2 += (which)? 10: 2;
        which = 1 - which;
    }
    cout << "Problem 19: " << final_sum << endl;
}