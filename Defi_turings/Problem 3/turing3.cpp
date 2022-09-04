// Problem Statement
// What is the maximum prime factor of 20130101 ?

// For example, the maximum prime factor of 105 is 7 since 7x5x3.
// 

// Analysis
// Primarily, every numbers can be expressed as product of its factors.
// We can find each prime factor of the the given number and remove each of its occurances.
// To achieve this, we will pass through every prime numbers 
// and check whether it is a factor and remove ea(NUMBER!=1)? NUMBER: max_fact(NUMBER!=1)? NUMBER: max_factch occurence of the number.
// The number has no more occurance of the previous factor.
// ...
// We repeat this process until the number becomes a prime number or 1
// If the number becomes 1 return the previous value of the number
// Else return the number

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    vector<int> primes;
    int NUMBER = 20130101;
    // Adding the first prime factor
    primes.push_back(2);
    int max_fact = 1;
    // Case NUMBER is even - We remove the even part
    if (NUMBER%2==0){
        while (NUMBER%2==0){
            NUMBER /= 2;
        }
        max_fact = 2;
    }
    // At this level, the number is either 1 or another odd number
    int fact = 3;
    double power_number = pow(NUMBER, 0.5);
    while (fact<=power_number){
        // Check if fact is prime.
        // If it is the case, push it to primes and check if it divides NUMBER
        double root = pow(fact, 0.5);
        int i = 0; bool fact_is_prime = true;
        while ((primes[i]<=root)&&fact_is_prime){
            if (fact%primes[i]==0){
                fact_is_prime = false;
            }
            i++;
        }
        // If the number is prime
        if (fact_is_prime){
            // Add him to the list of prime numbers
            primes.push_back(fact);
            bool is_factor_of_number = NUMBER%fact==0;
            if (is_factor_of_number){
                while (is_factor_of_number) {
                    NUMBER /= fact;
                    is_factor_of_number = NUMBER%fact==0;
                }
                max_fact = fact;
                power_number = pow(NUMBER, 0.5);
            }
        }
        fact += 2;
    }
    cout << "Problem 3: " << ((NUMBER!=1)? NUMBER: max_fact) << endl;
    return 0;
}