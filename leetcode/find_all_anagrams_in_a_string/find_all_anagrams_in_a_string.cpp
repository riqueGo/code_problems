/*
 * Time Complexity: O(N)
 *   - N is the length of string `s`.
 *   - Each character is visited at most twice (once by `r`, once by `l`) → sliding window.
 *
 * Space Complexity: O(1)
 *   - Fixed-size array `letters[26]` is used regardless of input size.
 *   - Output list `ans` is not counted toward complexity since it depends on number of anagrams found.
 */

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int letters [26] = {0};
        int maxP = p.size(), l = 0, r = 0;
        for(int i = 0; i < maxP; i++) letters[p[i]-'a']++;
        
        vector<int> ans;
        while(r < s.size()) {
            if(letters[s[r] - 'a'] > 0) {
                letters[s[r++] - 'a']--;
                maxP--;
                if(maxP == 0) {
                    ans.emplace_back(l);
                    letters[s[l++] - 'a']++;
                    maxP++;
                }
            } else {
                while(s[l] != s[r]) {
                    letters[s[l++] - 'a']++;
                    maxP++;
                } 
                l++;
                r++;
            }
        }
        return ans;
    }
};