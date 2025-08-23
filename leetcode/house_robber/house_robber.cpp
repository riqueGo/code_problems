/*
Approach:
    - This uses dynamic programming with constant space.
    - At each step, we decide whether to take the current house's money plus the value two steps back (prev)
      or skip it and keep the current max (curr).
    - prev = max value until i-2
    - curr = max value until i-1

Time Complexity:
    - O(n) → We iterate through the nums array once.
Space Complexity:
    - O(1) → Only a few variables (prev, curr, tmp) are used.

*/

#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, curr = 0, tmp;
        for(int i = 0; i < nums.size(); i++) {
            tmp = curr;
            curr = max(curr, prev+nums[i]);
            prev = tmp;
        }
        return curr;
    }
};
