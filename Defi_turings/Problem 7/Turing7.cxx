#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	 vector<int> primes;
	 int index= 23456;  // pow(10, 7)
	 // add the first trivial prime
	 primes.push_back(2);
	 index--;
	 // fetch primes from 3
	 int number = 3;
	 bool is_prime; int root;
	 while(index){
	 	is_prime = true;
	 	root = pow(number, 0.5) + 1;
	 	for (int i=0; (primes[i]<root)&&(is_prime); i++){
	 		if (number%primes[i]==0)
	 			is_prime = false;
	 	}
	 	if (is_prime){
	 		primes.push_back(number);
	 		index --;
	 	}
	 	number += 2;
	 }
	 cout	<< "Problem 7: " 
	 			<< primes.back() 
	 			<< endl;
}