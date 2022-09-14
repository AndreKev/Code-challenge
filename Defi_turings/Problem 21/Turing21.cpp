// How can I generate combinations with C++
#include <iostream>
#include <vector>
#include <list>
#include <bits/stdc++.h>

#define MAX_YEAR 2013

using namespace std;


vector<int> generate(list<int> digits, int front, int remainder);

int count_uniques_sorted(vector<int>);
int largest_interval(vector<int>);

void print(vector<int> years){
    for (int year: years)
        cout << year << endl;
    cout << endl;
}

int main(){
    vector<int> years;
    list<int> digits;
    //  add digits to the list
    for (int i=0; i<10; i++)
        digits.push_back(i);

    years = generate(digits, 0, 4);
    sort(years.begin(), years.end());

    //print(years);
    cout << "Problem 21: " << count_uniques_sorted(years) * largest_interval(years) << endl;
}

vector<int> generate(list<int> digits, int front, int remainder){
    if (remainder==0)
        return (vector<int>){};
    else {
        vector<int> aux_years;
        int aux_dig, back;
        for (int i=0; i<digits.size(); i++){
            back = digits.back();
            aux_dig = front*10 + back;
            //for (int i=0; i<remainder; i++) cout << "\t";
            //    cout << aux_dig << endl;
            digits.pop_back();
            if ((aux_dig>0))    // remainder == 0 will avoid having redundance
                aux_years.push_back(aux_dig); // Adding the digits with the actual front
            // Add the elements of the Generate... to the actual years
            for (int element: generate(digits, aux_dig, remainder-1)){
                if (element<=MAX_YEAR) aux_years.push_back(element);
            }
            digits.push_front(back);
        }
        return aux_years;
    }
}

int count_uniques_sorted(vector<int> numbers){
    if (numbers.size()>1){
        // If the back is then begining then the list contains only one element
        if ((numbers.back()==numbers[0])) return 1;
        
        int uniques = 0;
        // Else it contains more than one element
        int pred = numbers.back();  // We place the back first because it will be displaced
        for (int number: numbers){
            if (number!=pred){
                pred = number;
                uniques += 1;
            }
        }
        return uniques;
    } else 
        return numbers.size();
}

int largest_interval(vector<int> years){
    int size = 0;
    int pred = years[0];
    int aux;
    for (int year:years){
        aux = year - pred;
        if (size<aux) 
                size = aux;
        pred = year;
    }
    return size;
}