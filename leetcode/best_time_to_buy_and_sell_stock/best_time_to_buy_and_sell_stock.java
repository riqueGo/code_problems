package best_time_to_buy_and_sell_stock;

class Solution {
    public int maxProfit(int[] prices) {
        int curr = prices[0];
        int max = 0;

        for(int i = 1; i < prices.length; i++) {
            if(prices[i] < curr) {
                curr = prices[i];
            } else {
                int tmp = prices[i] - curr;
                max = max > tmp ? max : tmp;
            }
        }
        return max;
    }
}
