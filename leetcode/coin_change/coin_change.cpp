/*
 * Time Complexity: O(S * N)
 *   - S is the amount, N is the number of coins.
 *   - For each amount up to S, we check all N coins.
 *
 * Space Complexity: O(S)
 *   - For the dp array of size amount+1.
 */

#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
using std::min;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp [amount+1];
        dp[0] = 0;

        sort(coins.begin(), coins.end());
        int currIndex;

        for(int c = 1; c <= amount; c++) {
            dp[c] = INT_MAX;
            for(int i : coins) {
                currIndex = c-i;
                if(currIndex < 0) break;
                else if(dp[currIndex] != INT_MAX) dp[c] = min(dp[c], dp[currIndex]+1);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};