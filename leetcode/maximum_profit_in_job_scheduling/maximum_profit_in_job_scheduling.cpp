/*
Time Complexity:
    - Sorting jobs: O(n log n)
    - Recursive DP (with memoization): O(n log n)
        * For each job (n), we do a binary search (O(log n)) to find the next compatible job.
    - Total: O(n log n)

Space Complexity:
    - jobs array: O(n)
    - cache (DP table): O(n)
    - recursion call stack: O(n) in the worst case
    - Total: O(n)
*/

#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::sort;

class Solution {
private:
    int fn(int i, const vector<vector<int>>& jobs, vector<int>& cache) {
        if(i == jobs.size()) return 0;

        if(cache[i] != -1) return cache[i];

        int ans = fn(i+1, jobs, cache);

        int l = i+1, r = jobs.size(), m = jobs.size();

        while(l < r) {
            m = l + (r-l)/2;
            if(jobs[m][0] >= jobs[i][1]) r = m;
            else l = m+1;
        }
        return cache[i] = max(ans, jobs[i][2] + fn(r, jobs, cache));
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs (n, vector<int>(3));
        vector<int> cache(n, -1);

        for(int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(), jobs.end());
        return fn(0, jobs, cache);
    }
};

int main() {
    Solution s;
    vector<int> startTime = {1,2,3,4,6};
    vector<int> endTime = {3,5,10,6,9};
    vector<int> profit = {20,20,100,70,60};
    s.jobScheduling(startTime, endTime, profit);
}