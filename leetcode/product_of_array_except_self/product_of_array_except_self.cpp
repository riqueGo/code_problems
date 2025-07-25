/*
 * Time Complexity: O(N)
 *   - N is the length of the input array.
 *   - Each element is visited a constant number of times.
 *
 * Space Complexity: O(1) (excluding the output array)
 *   - Only a constant amount of extra space is used for variables.
 *   - The output array is not counted as extra space.
 */

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        ans[0] = 1;

        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1]*nums[i-1];
        }

        int tmp = 1;
        for(int i = n-1; i >= 0; i--) {
            ans[i]*=tmp;
            tmp*=nums[i];
        }
        
        return ans;
    }
};