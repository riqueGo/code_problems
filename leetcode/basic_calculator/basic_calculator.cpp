/*
Time Complexity: O(n)
    - We iterate through each character in the string exactly once.
    - Each operation inside the loop (digit parsing, sign handling, stack push/pop) takes O(1) time.
Space Complexity: O(n)
    - In the worst case, if the expression is heavily nested with parentheses, 
      we push a sign context for each one, requiring O(n) stack space.
*/

#include <string>
#include <stack>
#include <cctype>

using std::string;
using std::stack;

class Solution {
public:
    int calculate(const string& s) {
        int n = s.size();
        int result = 0;
        int sign = 1; // current sign to apply to the next number
        stack<int> signStack;
        signStack.push(1); // global sign

        int i = 0;
        while (i < n) {
            char c = s[i];

            if (c == ' ') {
                i++; // skip spaces
            } 
            else if (isdigit(c)) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num; // apply the current sign
            } 
            else if (c == '+') {
                // next number takes current context sign
                sign = signStack.top();
                i++;
            } 
            else if (c == '-') {
                // next number will be negative in the current context
                sign = -signStack.top();
                i++;
            } 
            else if (c == '(') {
                // push current sign context for the sub-expression
                signStack.push(sign);
                i++;
            } 
            else if (c == ')') {
                // pop the sign context
                signStack.pop();
                i++;
            } 
            else {
                i++; // skip unexpected chars
            }
        }

        return result;
    }
};


int main() {
    Solution sol;
    string expression = "1-(     -232)+4";
    int result = sol.calculate(expression);
    return result; // Should return -4
}