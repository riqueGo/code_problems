/*
 * Time Complexity: O(N^2)
 *   - N is the length of the input string.
 *   - For each character, we expand around the center, resulting in O(N^2) total checks.
 *
 * Space Complexity: O(1)
 *   - Only a constant amount of extra space is used (excluding input and output).
 */

#include <string>

using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
        int startIdx, longestSize = 0, limit = s.length();

        for(int k = 0; k < limit; k++) {
            for(int i = k, j = k; i >= 0 && j < limit && s[i] == s[j]; i--, j++) {
                if(j-i > longestSize) {
                    longestSize = j-i;
                    startIdx = i;
                }
            }

            for(int i = k, j = k+1; i >= 0 && j < limit && s[i] == s[j]; i--, j++) {
                if(j-i > longestSize) {
                    longestSize = j-i;
                    startIdx = i;
                }
            }
        }
        return s.substr(startIdx, longestSize+1);
    }
};