package permutattions;

import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<List<Integer>> ans;
    private int maxAllowed;
    private int[] nums;

    public List<List<Integer>> permute(int[] nums) {
        this.nums = nums;
        this.maxAllowed = nums.length;
        this.ans = new ArrayList<>();
        List<Integer> currPerm = new ArrayList<>();
        fn(currPerm, 0);
        return ans;
    }

    private void fn(List<Integer> currPerm, int targetIndex) {
        if(currPerm.size() >= maxAllowed) {
            ans.add(new ArrayList<>(currPerm));
            return;
        }

        currPerm.add(nums[targetIndex]);
        fn(currPerm, targetIndex+1);
        for(int i = targetIndex; i > 0; i--) {
            int tmp = currPerm.get(i);
            currPerm.set(i, currPerm.get(i-1));
            currPerm.set(i-1, tmp);
            fn(currPerm, targetIndex+1);
        }
        currPerm.remove(0);
    }
}
