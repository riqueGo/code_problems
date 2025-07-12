/*
 * Time Complexity: O(N)
 *   - N is the length of the strings.
 *
 * Space Complexity: O(1)
 *   - Fixed-size array for character counts.
 */

#include<iostream>
#include<string>

using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int alpha [26] = {0};
        for(char ch : s) {
            alpha[ch-'a']++;
        }

        for(char ch : t) {
            if(alpha[ch-'a'] == 0) return false;
            alpha[ch-'a']--;
        }

        return true;
    }
};