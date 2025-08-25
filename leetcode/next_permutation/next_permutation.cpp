/*
Explanation:
1. Find the first decreasing element from the end (pivot).
2. Find the next larger element to swap with pivot.
3. Reverse the suffix to get the smallest lexicographic order.

Time Complexity:
    - O(n) → In worst case, full reverse and two scans of the array.
Space Complexity:
    - O(1) → In-place swaps and reversal.
*/

#include<vector>
#include<algorithm>

using std::vector;
using std::swap;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i > 0 && nums[i-1] >= nums[i]) --i;

        if(i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = nums.size()-1;
        while(j >= i && nums[j] <= nums[i-1]) --j;

        swap(nums[i-1], nums[j]);
        reverse(nums.begin()+i, nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,4,3,2};
    sol.nextPermutation(nums);
    return 0;
}