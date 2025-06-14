#include<vector>
#include<algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0], maxCurr = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxCurr = max(maxCurr+nums[i], nums[i]);
            maxSub = max(maxCurr, maxSub);
        }
        return maxSub;
    }
};