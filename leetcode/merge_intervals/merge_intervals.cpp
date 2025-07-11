#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::max;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        int i = 1, maxInterval;
        while(i < intervals.size()) {
            if(intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i++]);
            } else {
                maxInterval = ans.back()[1];
                while(i < intervals.size() && intervals[i][0] <= maxInterval) maxInterval = max(maxInterval, intervals[i++][1]);
                ans.back()[1] = maxInterval;
            }
        }

        return ans;
    }
};