#include <iostream>
#include <vector>
#include <list>
#define MAXDIGITS 9
using namespace std;

long long generate(list<int> digits, long long prefix, int divident);

int main(){
    list<int> digits = {1,2,3,4,5,6,7,8,9};
    cout << "Problem 26: " << generate(digits, 0, 1) << endl;
}

long long generate(list<int> digits, long long prefix, int divident){   // Initially we have digits, prefix-0 and divident 1
    if (divident>MAXDIGITS)
        return prefix;
    else {
        long long aux_digit;
        int back;
        for (int i=0; i<digits.size(); i++){
            back = digits.back(); digits.pop_back();
            aux_digit = prefix*10+back;
            if (aux_digit%divident==0){
                aux_digit = generate(digits, aux_digit, divident+1);
                if (aux_digit!=-1){
                    return aux_digit;
                } else 
                    digits.push_front(back);
            }
            else {
                digits.push_front(back);
            }
        }
        return -1; 
    }
}