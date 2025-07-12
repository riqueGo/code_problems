/*
 * Time Complexity: O(N)
 *   - N is the number of tokens.
 *   - Each token is processed once.
 *
 * Space Complexity: O(N)
 *   - Stack can grow up to N/2 in the worst case.
 */

#include <vector>
#include <stack>
#include <string>

using std::vector;
using std::stack;
using std::string;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tokensStack;
        int a, b;
        for(string token : tokens) {
            if(!isOperand(token)) {
                tokensStack.push(stoi(token));
                continue;
            } 
            
            b = tokensStack.top();
            tokensStack.pop();
            a = tokensStack.top();
            tokensStack.pop();

            if (token == "+") tokensStack.push(a+b);
            else if (token == "-") tokensStack.push(a-b);
            else if (token == "*") tokensStack.push(a*b);
            else tokensStack.push(a/b);
        }
        return tokensStack.top();
    }

    bool isOperand(string op) {
        return op == "+" || op == "-" || op == "*" || op == "/";
    }
};