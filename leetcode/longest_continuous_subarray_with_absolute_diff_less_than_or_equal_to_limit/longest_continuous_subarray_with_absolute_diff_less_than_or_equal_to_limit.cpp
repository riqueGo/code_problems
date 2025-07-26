/*
 * Time Complexity: O(N)
 *   - N is the length of the input array.
 *   - Each element is added and removed from each deque at most once.
 *
 * Space Complexity: O(N)
 *   - In the worst case, all elements are stored in the deques.
 */

#include <vector>
#include <deque>
#include <algorithm>

using std::vector;
using std::deque;
using std::max;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> inc, dec;
        int maxLen = 0, l = 0;

        for(int r = 0; r < nums.size(); ++r) {
            while(!inc.empty() && nums[r] < inc.back()) inc.pop_back();
            inc.push_back(nums[r]);

            while(!dec.empty() && nums[r] > dec.back()) dec.pop_back();
            dec.push_back(nums[r]);

            while(dec.front() - inc.front() > limit) {
                if(inc.front() == nums[l]) inc.pop_front();
                if(dec.front() == nums[l]) dec.pop_front();
                ++l;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};