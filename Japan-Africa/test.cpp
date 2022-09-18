#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int find(vector<int> vec, int value){
    for (int i=0; i<vec.size(); i++){
        if (vec[i]==value)
            return i;
    }
    return -1;
}

int main(int argc, char *argv[]) {
  vector<int> woods;
  int aux;
  // read the standard input
  while (!cin.eof()) {
    cin >> aux;
    woods.push_back(aux);
  }
  // store the Max length
  int L = woods.back(); woods.pop_back();
  // Sort the woods.
  sort(woods.begin(), woods.end());
  // Retrive the value
  int count;
  vector<int> remainder;
  while (woods.back()>5){
    count += 1;
    remainder.push_back(L-woods.back());
    woods.pop_back()
  }
  sort(remainder.begin(), remainder.end());
  
  // through woods
  for (int i=0; i<woods.size(); i++){
    int index = find(remainder, woods[i]);
    if (index != -1){
        remainder[index] = 0;
        woods[i] = 0;
    } else {
        continue;
    }
  }
  // woods with zeros and remainders.
  for (int i=0; i<woods.size(); i++){
    if (woods[i]!=0){
        sort(remainder.begin(), remainder.end());
        auto f = find(remainder.begin(), remainder.end(), woods[i]);
        if (f!=remainder.end()){
            int ind = f-remainder.begin();
            woods[i] = 0;
            remainder[ind] = 0;
        } else {
            auto f1 = find(remainder.begin(), remainder.end(), L-woods[i]);
            if (f1!=remainder.end()){
                int ind = f1-remainder.begin();
                woods[i]
            }
        }

    }
  }
  return 0;
}
