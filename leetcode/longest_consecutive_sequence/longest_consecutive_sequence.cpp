/*
 * Time Complexity: O(N)
 *   - Building the unordered_set takes O(N).
 *   - Each number is visited at most twice: once as a sequence start, and once in the while loop.
 *   - Overall linear time on average (hash set lookup is O(1) expected).
 *
 * Space Complexity: O(N)
 *   - The unordered_set stores all unique numbers.
 */

#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::max;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s (nums.begin(), nums.end());

        int ans = 0;
        for(int num : s) {
            if(s.find(num-1) != s.end()) continue;

            int count = 1, currNum = num;
            while(s.find(++currNum) != s.end()) {
                count++;
            }

            ans = max(count, ans);
        }

        return ans;
    }
};
