#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 
int nine(vector<int>);
int neuf(vector<int>);
int three(vector<int>);
int trois(vector<int>);
//

int main(){
    vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool not_found = true;
    int THREE, NINE, TROIS, NEUF, product;
    do {
        THREE = three(numbers);
        if (THREE%9==0){
            NEUF  = neuf(numbers);
            if (NEUF%9==0){
                NINE  = nine(numbers);
                if (NINE%3==0){
                    TROIS = trois(numbers);
                    if (TROIS%3==0){
                        product = THREE*NINE;
                        if (product == NEUF*TROIS)
                            not_found = false;  // We found the product
                    }
                }
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end())&&not_found) ;
    cout << "Problem 16: " << product << endl;
}

int nine(vector<int> numbers){
    return numbers[4]*1000+numbers[5]*100+numbers[4]*10+numbers[3];
}

int neuf(vector<int> numbers){
    return numbers[4]*1000+numbers[3]*100+numbers[8]*10+numbers[9];
}

int trois(vector<int> numbers){
    return numbers[0]*10000+numbers[2]*1000+numbers[6]*100+numbers[5]*10+numbers[7];
}

int three(vector<int> numbers){
    return numbers[0]*10000+numbers[1]*1000+numbers[2]*100+numbers[3]*10+numbers[3];
}

// THREE x NINE = TROIS * NEUF      // THRENIOSUF