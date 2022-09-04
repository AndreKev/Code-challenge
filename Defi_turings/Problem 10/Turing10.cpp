// Problem Statement
/* Find the sum of prime number less than 10 million */

// Analysis
//  We find the prime numbers less than 10million and add them.
//  We know a number is prime if it has no prime divisor less than it's square root.
//  Hence for every numbers less than 10 millions, we will compare it to the primes less than it's root.
//  No number can have a prime divisor greater than root(10million) since it is the max value

#include <iostream>
#include <vector>
#include <cmath>
// #include <bits/stdc++.h>  -> just wanted to try the function accumulate
using namespace std;

int main(){
    // This variable will store the prime numbers
    vector<int> primes = {2};
    // This is a counter to 10 million, ignoring even numbers.
    int number = 3;
    // Our maximum value
    int max = 10000000;
    // The root of the max value. We will not store a prime number less than this, but directly add it
    int root_max = pow(max, 0.5)+2;
    // The variable containg the added values. Must be >= long to avoid overflow
    long sum = 2;
    // iteration over [3. 10000000]
    while (number<max){
        // The root of the current number
        int root = pow(number, 0.5)+1;
        int i = 0; bool is_prime = true;
        // Check if there is a prime divisor less than the number
        while ((primes[i]<root)&&(is_prime)){
            // is true, there exist a prime divisor, hence the current number is not prime
            if (number%primes[i]==0){
                is_prime = false;
            }
            i++;    // Increment
        }
        // Checks is the number is prime by its boolean value
        if (is_prime) {
            sum += number;  // adding it to the variable if it is prime
            if (number<=root_max)
                primes.push_back(number);   // We store the variable only if it is less than the root of the max
        }
        number += 2;        // increment
    }
    cout << "Problem 10: " << sum << endl;      // Good bye !
}