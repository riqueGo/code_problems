#include<vector>
#include<algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currVec;
        sort(candidates.begin(), candidates.end());

        currVec.push_back(candidates[0]);
        combinations(ans, candidates, currVec, target, 0, candidates[0]);
        currVec.pop_back();
        combinations(ans, candidates, currVec, target, 1, 0);

        return ans;
    }

    bool combinations(
        vector<vector<int>>& ans,
        vector<int>& candidates,
        vector<int>& currVec,
        int target,
        int currIndex,
        int currSum
    ) {
        if(currSum == target) {
            ans.push_back(vector<int>(currVec));
            return true;
        }

        if(currIndex >= candidates.size()) return false;

        int tmpCurrSum = currSum + candidates[currIndex];
        if(tmpCurrSum > target) return false;

        currVec.push_back(candidates[currIndex]);
        bool first = combinations(ans, candidates, currVec, target, currIndex, tmpCurrSum);
        currVec.pop_back();
        if(!first) combinations(ans, candidates, currVec, target, currIndex+1, currSum);

        return false;
    }
};