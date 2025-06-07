package two_sum;

import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> posByValue = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            int curr = nums[i];
            if(posByValue.containsKey(target-curr)) {
                return new int[]{posByValue.get(target-curr), i};
            } else {
                posByValue.put(curr, i);
            }
        }
        return new int[]{};
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] result = s.twoSum(new int[]{2,7,11,15}, 9);
        for(int r : result) {
            System.out.print(r + " ");
        }
    }
}