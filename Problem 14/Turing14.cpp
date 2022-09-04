#include <iostream>
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono;
long long next(long long);  // Gives the next number of the series of seracus given an integer
long long solution2(long long);

// Class to solve this problem faster
class Problem14{
    public:
        Problem14(){};
        long long find_and_store(long long number);
        long long find_max_index(long long MAX);
    private:
        map<int, int> length;
        int min_index;
};


int main(){
    Problem14 problem = Problem14();
    int MAX = 1500000;
    auto t1 = high_resolution_clock::now();
    long long a1 = problem.find_max_index(MAX);
    auto t1s = high_resolution_clock::now();
    long long a2 = solution2(MAX);
    auto t1ss = high_resolution_clock::now();
    cout << "Problem 14: " << a1 << "\t" << flush << a2 << endl;
    cout << "Time 1:: " << duration_cast<seconds>(t1s-t1).count() << "\tTime 2:: " << duration_cast<seconds>(t1ss-t1s).count() << endl;
    return 0;
}

// Defining the methods of the class
long long Problem14::find_and_store(long long number){
        if (number==1){
            return 1;
        }
        if (length[number]<2)// If we already know the result
            length[number] = 1 + find_and_store(next(number));
        return length[number];
}

long long Problem14::find_max_index(long long MAX){
    MAX += 1;
    long long current;
    int min_index = 0;
    for (int i=1; i<MAX; i++){
        if (length[i]<2){
            length[i] = find_and_store(i);
        }
        if (length[i]>length[min_index])
            min_index = i;
    }
    return min_index;
}
// First implementation, but we can achieve better than this
long long solution2(long long MAX){
    MAX += 1;
    // Initialize a vector of length MAX with values 1
    map<int, int> length;
    long long current, cnext;
    int min_index = 0;
    for (int i=1; i<MAX; i++){
        length[i] = 1;
        current = i;
        while (current!=1){
            if ((length[current]>1)){
                length[i] += length[current]-1;
                current = 1;
            } else {
                length[i] += 1;
                current = next(current);
            }
        }
        if (length[i]>length[min_index]) min_index = i;
    }
    return min_index;
}

long long next(long long current){
    return ((current%2)? 3*current+1: current/2);
}