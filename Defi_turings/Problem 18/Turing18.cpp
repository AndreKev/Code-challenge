// Problem Statement
/*
    A number is said to be abundant if the sum of all its clean divisors is greater than it.

    What is the sum of all numbers less or equal to 2013, that can not be written as the sum of 
    two abundant numbers.
*/

// Analysis
/*
    We will find the sum of all the clean factors of numbers between 1 and 2013 and keep it in a map.
    The we will iterate through this map. if a number is not abundant, we find in numbers below 
    if there are abundant numbers N, M such that N+M is the actual number and N and M are abundant.

    This is a linear search.

    Afterall a faster solution is to generate all the numbers that can be the sum of two abundant numbers.
    We can find them by adding two by two every abundant numbers in the provided interval, then substract all
    of the generated numbers from the sum of all integers in the interval.
*/

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int sum_of_factors(vector<int>, map<int, int>);
vector<int> merge(vector<int>, int, int);
int sum(vector<int>);

int main(){
    int MAX = 2013+1;   // +1 because 2013 is included.

    int number;
    vector<int> primes = {2};
    // To be used in the while loop
    int root, i;
    bool is_prime;
    vector<int> factors;
    map<int, int> occurence, map_of_sums;
    unsigned long final_sum = 0;
    int aux, prime_number = 3;
    for (number = 3; number<MAX; number++){
        //
        factors.clear();
        occurence.clear();
        //
        root = (int)pow(number, 0.5)+1;
        // add possible square roots of the number to the list of prime numbers
        while ((prime_number<root)){
            int prime_root = pow(prime_number, 0.5)+1;
            int i = 0; is_prime = true;
            while ((primes[i]<prime_root)&&is_prime){
                if (prime_number%primes[i]==0){
                    is_prime = false;
                }
                i++;
            }
            if (is_prime){
                primes.push_back(prime_number);
            }
            prime_number += 2;
        }
        // Add factors to the appropriate list.
        aux = number;
        for (int fact: primes){
            if (aux%fact==0)
                factors.push_back(fact); 
            while (aux%fact==0){
                occurence[fact] += 1;
                aux /= fact;
            }
        }
        if (aux!=1){
            factors.push_back(aux);
            occurence[aux] = 1;
        }
        map_of_sums[number] = sum_of_factors(factors, occurence)-number;
    }
    bool not_found;
    for (int i=1; i<MAX; i++){
        //cout << i << endl;
        not_found = true;
        if (false){        //((map_of_sums[i]<i)&&false){
            final_sum += i;
        }
        else {
            int mid = i/2-1;
            for (int k=i; (k>mid)&&not_found; k--){
                if ((map_of_sums[k]>k)&&(map_of_sums[i-k]>(i-k))){
                    not_found = false;
                    //cout << i << endl;
                    //cout << "\t" << k << "\t" << i-k << endl;
                }
            }
            if (not_found)
                final_sum += i;
        }
    }
    cout << "Problem 18: " << final_sum << endl;
}

int sum_of_factors(vector<int> factors, map<int, int> occurence){
    vector<int> init_fact = {1};
    for (int fact: factors){
        init_fact = merge(init_fact, fact, occurence[fact]);
    }
    //cout << "Printing factors." << endl;
    //for (int val: init_fact) 
    //    cout << val << " ";
    //cout << endl;
    return sum(init_fact);
}

vector<int> merge(vector<int> initial, int number, int power){
    vector<int> output;
    for (int _pow = 0; _pow<=power; _pow++){
        for (int value: initial){
            output.push_back(value*(int)pow(number,_pow));
        }
    }
    return output;
}

int sum(vector<int> vect){
    int output = 0;
    for (int value: vect){
        output += value;
    }
    return output;
}