package longest_continuous_subarray_with_absolute_diff_less_than_or_equal_to_limit;

import java.util.Deque;
import java.util.LinkedList;

class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> inc = new LinkedList<>();
        Deque<Integer> dec = new LinkedList<>();
        int maxLen = 0, l = 0;

        for (int r = 0; r < nums.length; ++r) {
            while (!inc.isEmpty() && nums[r] < inc.peekLast()) inc.pollLast();
            inc.addLast(nums[r]);

            while (!dec.isEmpty() && nums[r] > dec.peekLast()) dec.pollLast();
            dec.addLast(nums[r]);

            while (dec.peekFirst() - inc.peekFirst() > limit) {
                if (inc.peekFirst() == nums[l]) inc.pollFirst();
                if (dec.peekFirst() == nums[l]) dec.pollFirst();
                ++l;
            }
            maxLen = Math.max(maxLen, r - l + 1);
        }
        return maxLen;
    }
}
