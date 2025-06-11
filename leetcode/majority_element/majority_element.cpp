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