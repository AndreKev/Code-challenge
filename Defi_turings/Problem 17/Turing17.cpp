// Problem Statement
/*
    Let d(n) be the sum of the clean divisors of n(all divisors of n strictly less_ than n).
    if d(a)=b and d(b)=a, with distinct a, b; then a and b are said
        to be friends.
    
    For exemple, the clean divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110.
    Hence d(220) = 284.
    The clean divisors of 284 are 1, 2, 4,71 and 142. 
    Hence d(284) = 220.
    Therefore 220 and 284 are friends. 

    So 220 and 284 are friends. The sum of all friends between 1 and 1000 is 220 + 284 = 504.

    What is the sum of all friends between 1 and 100000 ?
*/

// Analysis
/*
    We already know that the sum of friends between 1 and 1000 is 504. 
    Good. We will add it to the friends between 1000 and 100000.

    if a and b are friends and distinct,
        [1] d(b) = a 
        [2] d(a) = b,
    by substituting [2] in [1], we obtain
        [3] d(d(a)) = a; and a different from d(a)l
    Which is a sufficient condition to have (a, b) friends, with a and d(a) different.
    
    To know the sum of clean factors of a number we need to find them.
    We can determine all the factors of a number by combining the multiples of its prime factors.

    Example ::  24      = pow(2, 3) * pow(3, 1)
                fact(24)= {pow(2, 0)*pow(3, 0), pow(2, 0)*pow(3, 1), pow(2, 1)*pow(3, 0), pow(2, 1)*pow(3, 1),
                        pow(2, 2)*pow(3, 0), pow(2, 2)*pow(3, 1), pow(2, 3)*pow(3, 0), pow(2, 3)*pow(3, 1)
                } 
    Hence we listed all the possible combinations of its algorithms.
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
    int MAX = 100000;

    int number;
    vector<int> primes = {2};
    // To be used in the while loop
    int root, i;
    bool is_prime;
    vector<int> factors;
    map<int, int> occurence, map_of_sums;
    unsigned long final_sum = 220 + 284;
    int aux, prime_number = 3;
    for (number = 1000; number<MAX; number++){
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
    for (int i=3; i<MAX; i++){
        if ((map_of_sums[map_of_sums[i]]==i)&&(i!=(map_of_sums[i]))){
            final_sum+= i;
        }
            
    }
    cout << "Problem 17: " << final_sum << endl;
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