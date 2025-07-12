/*
 * Time Complexity: O(N)
 *   - N is the length of the string.
 *
 * Space Complexity: O(1)
 *   - Fixed-size array for character counts.
 */

#include <string>

using std::string;

class Solution {
public:
    int longestPalindrome(string s) {
        int letters [52] = {0};
        for(char ch : s) {
            if(ch < 'a') {
                letters[ch-'A']++;
            } else {
                letters[ch-'a'+26]++;
            }
        }

        bool hasOdd = false;
        int total = 0;
        for(int i = 0; i < 52; i++) {
            total+=letters[i];
            if(letters[i] % 2 != 0) {
                hasOdd = true;
                total-=1;
            } 
        }

        return hasOdd ? total + 1 : total; 
    }
};