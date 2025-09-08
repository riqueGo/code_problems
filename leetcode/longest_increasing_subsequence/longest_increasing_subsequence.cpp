/*
 * Time Complexity: O(N log N)
 *   - N is the size of the input array.
 *   - For each element, we perform a binary search in the tails array (O(log N)).
 *   - Overall: O(N log N).
 *
 * Space Complexity: O(N)
 *   - For the tails vector, which in the worst case can grow to size N.
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::max;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
        }
        return tails.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int result = sol.lengthOfLIS(nums);
    return 0;
}