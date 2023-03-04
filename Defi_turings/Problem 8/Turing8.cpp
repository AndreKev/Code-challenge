#include <iostream>
#include <vector>

using namespace std;

int main(){
    int NUMBER = 6400;

    auto y = [](double x, double r){
        return (2*r)/(x*(x+1)) + (x-1)/3;
    };
    int min_side;
    double max_side;
    
    vector<vector<int>> rsquares;
    for (int min_side=10; min_side<31; min_side++){
        max_side = y(min_side, NUMBER);
        if (max_side==int(max_side))
            rsquares.push_back({min_side, int(max_side)});
    }
    // Now we look for the closest pair
    long long distance = 100000000000;
    min_side = 0;
    max_side = min_side + distance;
    for (auto mn:rsquares){
        if (mn[1]-mn[0] < distance){
            distance = mn[1]-mn[0];
            min_side = mn[0]; max_side = mn[1];
        }
    }
    cout << "The area is " << min_side*max_side << endl;
    cout << "The sides are " << min_side << " and " << max_side << endl;
}