/*
 * Time Complexity: O(N)
 *   - N is the length of the input string.
 *   - Each character is processed at most once.
 *
 * Space Complexity: O(1)
 *   - Only a constant amount of extra space is used (excluding input and output).
 */

#include <string>
#include <stdexcept>
#include <limits.h>

using std::string;
using std::exception;

class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0) return 0;

        int i = 0;
        while(i < s.length() && s[i] == ' ') i++;

        bool isNegative = false;
        string ansStr = "";
        if(i < s.length() && (s[i] == '+' || s[i] == '-')) {
            isNegative = s[i] == '-';
            if(isNegative) ansStr += "-";
            i++;
        }

        while(i < s.length() && s[i] == '0') i++;

        int count = 0;
        while(i < s.length() && count < 11 && '0' <= s[i] && s[i] <= '9') {
            ansStr += s[i++];
            count++;
        }

        if(ansStr.length() == 0 || (isNegative && ansStr.length() == 1)) return 0;

        try {
            int ans = stoi(ansStr);
            return ans;
        } catch (exception& e) {
            return isNegative ? INT_MIN : INT_MAX;
        }
    }
};