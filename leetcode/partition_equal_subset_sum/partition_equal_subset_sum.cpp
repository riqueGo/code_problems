#include <vector>
#include <bitset>
#include <iostream>

using std::vector;
using std::bitset;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) sum += nums[i];
        
        if (sum % 2 != 0) return false;

        bitset<10001> bit(1);
        for (int i : nums) {
            bit |= bit << i;
            if (bit[sum / 2]) return true;
        }
        return bit[sum / 2];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 5, 11, 5};
    bool result = solution.canPartition(nums);
    std::cout << result;
}