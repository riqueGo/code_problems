#include <vector>

using std::vector;

class Solution {
private:
    int limit;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        limit = nums.size();
        vector<vector<int>> ans;
        vector<int> currAns;
        fn(ans, currAns, nums, 0);
        return ans;
    }

    void fn(vector<vector<int>>& ans, vector<int>& currAns, vector<int>& nums, int targetIndex) {
        if(currAns.size() >= limit) {
            ans.push_back(vector<int>(currAns));
            return;
        }

        currAns.push_back(nums[targetIndex]);
        fn(ans, currAns, nums, targetIndex+1);
        for(int i = targetIndex; i > 0; i--) {
            int tmp = currAns[i];
            currAns[i] = currAns[i-1];
            currAns[i-1] = tmp;
            fn(ans, currAns, nums, targetIndex+1);
        }
        currAns.erase(currAns.begin());
    }
};