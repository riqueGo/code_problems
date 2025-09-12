package longest_consecutive_sequence;

import java.util.HashSet;
import java.util.Set;

class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }

        int ans = 0;
        for (int num : set) {
            if (set.contains(num - 1)) continue;

            int count = 1, currNum = num;

            while (set.contains(++currNum)) {
                count++;
            }

            ans = Math.max(ans, count);
        }

        return ans;
    }
}