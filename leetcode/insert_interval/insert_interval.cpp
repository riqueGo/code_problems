#include<iostream>
#include<vector>
#include <algorithm>

using std::vector;
using std::min;
using std::max;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) return {newInterval};

        if(intervals[0][0] > newInterval[1]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }

        if(intervals.back()[1] < newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> ans;
        int i = 0;
        while(i < intervals.size() && newInterval[0] > intervals[i][1]) i++;

        ans.insert(ans.end(), intervals.begin(), intervals.begin()+i);

        for(;i < intervals.size() && newInterval[1] >= intervals[i][0]; i++) {
            newInterval = {
                min(newInterval[0], intervals[i][0]),
                max(newInterval[1], intervals[i][1])
            };
        }

        ans.push_back(newInterval);
        ans.insert(ans.end(), intervals.begin()+i, intervals.end());
        return ans;
    }
};