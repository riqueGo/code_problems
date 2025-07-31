/*
 * Time Complexity: O(n * k^n)
 *   - n = number of digits
 *   - k = max number of letters per digit (at most 4: for '7' and '9')
 *   - At each step, we build new combinations by appending k letters to each existing string
 *   - There will be up to k^n combinations, each of length n → total time is O(n * k^n)
 *
 * Space Complexity: O(n * k^n)
 *   - We store up to k^n strings, each of length n in the result vector
 */

#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};

        unordered_map<char, vector<string>> umap = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}
        };
        vector<string> ans = umap[digits[0]];

        for(int i = 1; i < digits.size(); i++) {
            vector<string> tmpAns;

            for(string s : ans) {
                for(string phone : umap[digits[i]]) {
                    tmpAns.emplace_back(s+phone);
                }
            }
            ans = tmpAns;
        }
        return ans;
    }
};