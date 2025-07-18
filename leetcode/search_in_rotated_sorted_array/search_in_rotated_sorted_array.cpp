/*
 * Time Complexity: O(log N)
 *   - N is the number of elements in the array.
 *   - Each iteration halves the search space.
 *
 * Space Complexity: O(1)
 *   - Only a constant amount of extra space is used.
 */

#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, m, r = nums.size()-1;

        while(l <= r) {
            m = l + ((r-l)/2);
            
            if(nums[m] == target) return m;
            else if(nums[l] <= nums[m]) {
                if(target > nums[m] || target < nums[l]) l = m+1;
                else r = m-1;
            } else {
                if(target < nums[m] || target > nums[r]) r = m-1;
                else l = m+1;
            }
        }
        return -1;
    }
};