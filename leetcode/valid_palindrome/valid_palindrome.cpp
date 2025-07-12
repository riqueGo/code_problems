/*
 * Time Complexity: O(N)
 *   - N is the length of the string.
 *
 * Space Complexity: O(1)
 *   - Only pointers and a few variables are used.
 */

#include<iostream>
#include<string>

using std::string;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while(left < right) {
            char leftChar = s[left],
                rightChar = s[right];

            if(!isAlphaNumeric(leftChar)) {
                left++;
                continue;
            }

            if(!isAlphaNumeric(rightChar)) {
                right--;
                continue;
            }

            if(isUpperCaseAlpha(leftChar)) leftChar = toLowerCase(leftChar);
            if(isUpperCaseAlpha(rightChar)) rightChar = toLowerCase(rightChar);

            if(leftChar != rightChar) return false;

            left++;
            right--;
        }
        return true;
    }

    bool isLowerCaseAlpha(char ch) { return ch >= 'a' && ch <= 'z'; }
    bool isUpperCaseAlpha(char ch) { return ch >= 'A' && ch <= 'Z'; }
    bool isNumeric(char ch) { return ch >= '0' && ch <= '9'; }
    bool isAlphaNumeric(char ch) { return isLowerCaseAlpha(ch) || isUpperCaseAlpha(ch) || isNumeric(ch); }
    char toLowerCase(char ch) { return 'z' - 'Z' + ch; }
};

int main() {
    Solution s;
    std::cout << s.isPalindrome("A man, a plan, a canal: Panama");
}