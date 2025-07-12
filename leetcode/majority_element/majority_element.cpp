/*
 * Time Complexity: O(N)
 *   - N is the number of elements in the array.
 *   - Each element is visited once.
 *
 * Space Complexity: O(1)
 *   - Only a constant amount of extra space is used.
 */

#include<vector>

using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int quantity = 0;
        for(int num : nums) {
            if(num == candidate) {
                quantity++;
                continue;
            }

            quantity--;
            if(quantity == 0) {
                candidate = num;
                quantity = 1;
            }
        }
        return candidate;
    }
};