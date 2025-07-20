/*
 * Time Complexity: O(2^N)
 *   - N is the number of elements in the input array.
 *   - Each element can be included or excluded, generating all possible subsets.
 *
 * Space Complexity: O(2^N * N)
 *   - For storing all subsets (each subset can have up to N elements).
 *   - Recursion stack space is O(N).
 */

#include <vector>

using std::vector;

class Solution {
private:
    void fn(vector<vector<int>>& ans, vector<int>& currAns, vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            ans.push_back(currAns);
            return;
        }

        currAns.push_back(nums[idx++]);
        fn(ans, currAns, nums, idx);
        currAns.pop_back();
        fn(ans, currAns, nums, idx);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currAns;
        fn(ans, currAns, nums, 0);
        return ans;
    }
};