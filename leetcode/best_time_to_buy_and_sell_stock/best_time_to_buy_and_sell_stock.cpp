/*
 * Time Complexity: O(N)
 *   - N is the number of days (prices).
 *   - Each price is visited once.
 *
 * Space Complexity: O(1)
 *   - Only a constant amount of extra space is used.
 */

#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = prices[0];
        int max = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < curr) {
                curr = prices[i];
            } else {
                int tmp = prices[i] - curr;
                max = tmp > max ? tmp : max;
            }
        }
        return max;
    }
};