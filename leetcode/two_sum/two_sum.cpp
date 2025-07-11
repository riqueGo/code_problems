/*
 * Time Complexity: O(N)
 *   - N is the length of the array.
 *
 * Space Complexity: O(N)
 *   - For the hash map.
 */

#include<iostream>
#include<vector>
#include<unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> posByValue;
        for(int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            if(posByValue.find(target-curr) != posByValue.end()) {
                return {posByValue[target-curr], i};
            } else {
                posByValue[curr] = i;
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums ={2,7,11,15};
    vector<int> result = s.twoSum(nums, 9);
    for(int r : result) {
        std::cout << r << " ";
    }
}