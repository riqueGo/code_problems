#include <vector>
#include<algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int j, k, total;

        for(int i = 0; i < nums.size()-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            j = i+1;
            k = nums.size()-1;

            while(j < k) {
                total = nums[i] + nums[j] + nums[k];
                if(total < 0) j++;
                else if (total > 0) k--;
                else {
                    ans.push_back({nums[i], nums[j++], nums[k]});
                    while(nums[j] == nums[j-1] && j < k) j++;
                }
            }
        }

        return ans;
    }
};