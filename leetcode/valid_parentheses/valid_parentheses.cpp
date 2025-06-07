#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>

using std::string;
using std::unordered_map;
using std::stack;


class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 != 0) return false;
        unordered_map<char, char> openByClose = {
            {')','('},
            {'}','{'},
            {']','['}
        };

        stack<char> bracketsStack;
        for(char ch : s) {
            if(openByClose.find(ch) != openByClose.end()) {
                if(bracketsStack.empty() || openByClose[ch] != bracketsStack.top()) {
                    return false;
                } 
                bracketsStack.pop();
            } else {
                bracketsStack.push(ch);
            }
        }

        return bracketsStack.empty();
    }
};

int main() {
    Solution s;
    std::cout << s.isValid("([])");
}