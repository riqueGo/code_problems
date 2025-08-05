/*
 * Time Complexity: O(N)
 *   - N is the length of string `s`.
 *   - Each character is visited at most twice (once by `right`, once by `left`) using sliding window.
 *
 * Space Complexity: O(1)
 *   - Fixed-size array of 128 characters is used for ASCII character tracking.
 *   - Space does not grow with input size.
 */

#include <string>
#include <unordered_map>
#include <climits>

using std::string;
using std::unordered_map;

class Solution {
public:
    string minWindow(string s, string t) {
        int letters [128] = {0};
        for (char c : t) letters[c]++;

        int left = 0, right = 0, count = t.size(), minLength = INT_MAX, start = 0;
        while (right < s.size()) {
            if (letters[s[right++]]-- > 0) count--;
            while (count == 0) {
                if (right - left < minLength) {
                    minLength = right - left;
                    start = left;
                }
                if (letters[s[left++]]++ == 0) count++;
            }
        }
        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};

int main() {
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string result = solution.minWindow(s, t);
    // Expected output: "BANC"
    return 0;
}