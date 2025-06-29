package coin_change;

import java.util.Arrays;

class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount+1];
        dp[0] = 0; // Base case: 0 coins needed to make amount 0

        Arrays.sort(coins);

        int currIndex;

        for(int c = 1; c <= amount; c++) {
            dp[c] = Integer.MAX_VALUE;
            for(int i : coins) {
                currIndex = c-i;
                if(currIndex < 0) break;
                else if(dp[currIndex] == Integer.MAX_VALUE) continue;
                dp[c] = Math.min(dp[c], dp[currIndex]+1);
            }
        }
        return dp[amount] == Integer.MAX_VALUE ? -1 : dp[amount];
    }

    public static void main(String[] args) {
        int[] coins = {1, 2, 5};
        int amount = 11;
        Solution solution = new Solution();
        int result = solution.coinChange(coins, amount);
        System.out.println("Minimum coins needed: " + result); // Output: 3
    }
}
