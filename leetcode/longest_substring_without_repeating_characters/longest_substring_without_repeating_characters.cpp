#include <string>
#include <algorithm>

using std::string;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;

        int i = 0, j = 0, ans = 0;
        char startChar = s[i], endChar;
        int table[256] = {0};
        while(j < s.length()) {
            endChar = s[j];

            if(table[endChar] == 0) {
                table[endChar]++;
                j++;
                continue;
            }

            ans = max(ans, j-i);

            while(startChar != endChar) {
                table[startChar]--;
                startChar = s[++i];
            }

            startChar = s[++i];
            j++;
        }

        ans = max(ans, j-i);
        return ans;
    }
};