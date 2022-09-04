// Problem Statement
/*
    The first palindrome sqaure number with an even number of digits is 698896 = 836*836.
        What is the next ?
*/

// Analysis
/*
    A simple solution will be a linear search,by squaring numbers more than 836
    and checking if the square is a palindrome with an even number of digits.

    We can restrict our search to a specific case to handle it faster.
    We know, 
        for a given number, 
            if its square has an even number of digits,
                then the first three digits of the number is greater than 316.
    Reason :: 10 is the first number with two digits. the root of 10 is 3.1622277..
    Hence  :: a number less than three cannot give a square with two digits
    Analogy:: this is similar for entire number where we consider the (log(number)+1) first digits.

    Since we know our numbers are at least greater than 836, then they have at least 3 digits.
    In this exercise we check the three_first digits of a number before checking its square
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_palindrome(long long);  // Check if a number is a palindrome
int three_first(int);           // Return the three first digits of a number. Ex three_first(3047) = 304

int main(){
    bool found = false;
    int number = 836;
    long long square;
    while (!found){
        number++;
        // We know the sqauare of a number can have a pair number of digits 
        // only if it's first three digits are more than 316
        // Since root(1000) == 31.622277...
        if (three_first(number)<316){
            number = (int)(0.3162227766*pow(10, log10(number)+1));
        }
        square = pow(number, 2);
        //cout << "is pal " << square << " " << is_palindrome(square) << endl;
        if (is_palindrome(square)&&(((int)log10(square)+1)%2==0)){
            found = true;
        }
    }
    // Output the result to the screen
    cout << "Problem 13: " << square << endl;
}

bool is_palindrome(long long number){
    vector<int> digits;
    // Place the digits in a vector
    while(number){
        digits.push_back(number%10);
        number /= 10;
    }
    // Now check if the number is a palindrome
    int begin = 0, end=digits.size()-1;
    while (begin<end){
        if (digits[begin]!=digits[end])
            return false;
        begin++; end--;
    }
    return true;
}

int three_first(int number){
    vector<int> digs;
    // Place the digits in a vector
    while (number){
        digs.push_back(number%10);
        number/=10;
    }
    int size = digs.size();
    return digs[size-1]*100+digs[size-2]*10+digs[size-3]; // return the 3 first digits
}