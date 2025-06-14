package maximum_subarray;

class Solution {
    public int maxSubArray(int[] nums) {
        int max = nums[0], maxCurr = nums[0];
        for(int i = 1; i < nums.length; i++) {
            maxCurr = Math.max(maxCurr+nums[i], nums[i]);
            max = Math.max(maxCurr, max);
        }
        return max;
    }
}
