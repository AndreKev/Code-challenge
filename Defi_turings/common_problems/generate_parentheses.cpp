#include <iostream>
#include <string>
#include <vector>

using namespace std;

void vectorprint(vector<string> vect);

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        short open = n, close = n;
        string s(" ", n*2);
        vector<string> returnArray;
        return solution(returnArray, s, open, close);
    }
    vector<string> solution(vector<string> returnArray, string s, short open, short close){
        if (open+close==0){
            returnArray.push_back(s);
            return returnArray;
        } else {
            int index = s.length()-open-close;
            if (open){
                s[index] = '(';
                returnArray = solution(returnArray, s, open-1, close);
            }
            if (open<close){
                s[index] = ')';
                returnArray = solution(returnArray, s, open, close-1);
            }
            return returnArray;
        }
    }
};

int main(){
    Solution problem;
    for (int i=1; i<100; ++i)
        vectorprint(problem.generateParenthesis(i));
    return 0;
}


void vectorprint(vector<string> vect){
    for (string s: vect)
        std::cout << s << "\t";
    std::cout << std::endl;
}
