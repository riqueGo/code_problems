/*
 * Time Complexity: O(M * N)
 *
 * Space Complexity: O(M * N)
 *  - For the 2D vector.
 */

#include <vector>

using std::vector;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp.back().back();
    }
};