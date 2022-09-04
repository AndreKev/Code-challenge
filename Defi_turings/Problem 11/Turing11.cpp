// Problem Statement
/* We call mirror of a number n. the number made of its digits from right to left.
example : mirror(3467) = 7643.

What is the greatest number, less than 10 million with the property
mirror(n) = 4 x n ? 
*/

// Analysis
/*
    A linear search gives a straight forward solution but is slow.
    Here we propose an approach that chooses the appropriate set of number for each digits.
    Exemple : since the number must be less than 10 million, and the number has the same number of digits
    as its mirror, then its mirror too is less than 10 million.
    We have : b
*/

#include <iostream>
#include <stack>
#include <chrono>
#include <set>
#include <vector>

using namespace std;

// We will create a class to store object tuple<set, set> 
class SetDuo{
    // Access specifier
    public:
        // Constructor
        SetDuo(){};
        SetDuo(set<int> afirst, set<int> aprime){first=afirst; prime=aprime;};
        // Data members(list<set>){afirst, aprime}(list<set>){afirst, aprime}
        set<int> first;
        set<int> prime;
};


// signatures
bool compare_mirror(long long, long long);
vector<int> add(vector<int>, set<int>);
SetDuo trans(set<int>, set<int>, int, int);

// main
int main(){
    auto start = chrono::high_resolution_clock::now();
    // number of digits
    int length_digits = 7;
    // The digits of the number#include <list>
    vector<SetDuo> number(length_digits);
    // We will continuously process the [1]digits until there is no more change in processing
    // The aim is to select the possible number the digits can take
    int changing = length_digits;   // If we do $length_digits iterations with(list<set>){afirst, aprime}out a change we stop
    SetDuo aux;                        // An auxiliary set to check whether the processed sets changed
    // Useful variables in processing
    set<int> prime;
    int max, min;
    // Start processing
    //cout << "Starting ... " << flush;
    while (changing){
        for (int i=0; i<length_digits; i++){
            if (i==0){
                prime = {0};
            } else prime = number[i-1].prime;
            if (i==1){
                max = 5;
            } else if(i==0){
                max = 2;
            } else max = 9;
            //min = 1 if i in (0, length_digits-1) else None
            min = ((i==0)||(i==length_digits-1))? 1: 0;
            aux = number[i];
            if (!number[length_digits-1-i].first.size()){
                number[length_digits-1-i].first = {0,1,2,3,4,5,6,7,8,9};
            }
            number[i] = trans(number[length_digits-1-i].first, prime, min, max);
            if ((aux.first == number[i].first) && (aux.prime == number[i].prime)){
                changing -= 1;
                if (!changing) break;
            } else changing = length_digits;
        }
    }
    //cout << "Ending while loop ..." << endl;
    // Now create a vector with all posible com{0}binations of digits
    vector<int> total = {0};
    //cout << "Creating lists with function add ... " << flush;
    for (auto& digit: number){
        //cout << "hey" << endl;
        total = add(total, digit.first);
        //for (int i=0; i<total.size(); i++) cout << total[i] << " ";
    }
    //cout << endl;
    //cout << "finished." << endl;
    // Now lets find the greatest number satisfying
    // mirror(n) == 4*nvector<int> vector<set> trans(set<int> first, set<int> prime, int min, int max)add(vector<int> part1, set<int> part2)
    int length = total.size()-1;
    while (length){
        //cout << "Comparing " << length << ": " << total[length] << endl;
        if (compare_mirror(total[length], 4*total[length])){
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end-start);
            cout << "Problem 11: " << total[length] << endl;
            cout << "time :: " << duration.count() << "s" << endl;
            break;
        }
        length--;
    }
}

vector<int> add(vector<int> part1, set<int> part2){
    vector<int> aux;
    for (int digit1: part1){
        for (int digit2: part2){
            aux.push_back(digit1*10+digit2);
        }
    }
    return aux;
}

SetDuo trans(set<int> first, set<int> prime, int min, int max){
    //cout << "IN " << first.size() << " " << prime.size() << " "; 
    if (!prime.size()) set<int> prime = {0};
    if (!first.size()) set<int> first = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 
    max += 1;
    set<int> afirst, aprime;
    // used in core
    int aux, auxfirst, auxprime;
    for (auto& numberf: first){
        for (auto& numberp: prime){
            //cout << numberp << " " << numberf << endl;
            aux = 4*numberf+numberp;
            auxfirst = aux%10;                        
            auxprime = aux/10;
            if ((min<=auxfirst)&&(auxfirst<max)){
                afirst.insert(auxfirst);
                aprime.insert(auxprime);
            }
        }
    }
    //cout << "OUT" << endl;
    return SetDuo(afirst, aprime);
}

bool compare_mirror(long long number1, long long number2){
    stack <int> digits;
    while(number1){
        digits.push(number1%10);
        number1 /= 10;
    }
    while (number2 && digits.size()){
        if (digits.top()!=number2%10) return false;
        digits.pop();
        number2 /= 10;
    }
    return !(number2);
}