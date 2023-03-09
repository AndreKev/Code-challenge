#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int main(){
    std::vector<std::vector<int>> v1 = {{1,2,3}, {1,2,6}};
    std::vector<int> v2 = {1,2,3};
    std::cout << binary_search(v1.begin(), v1.end(), v2) << std::endl;
}