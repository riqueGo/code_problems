package subsets;

import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<List<Integer>> ans;
    private List<Integer> currAns;
    private int[] nums;

    private void fn(int idx) {
        if(idx == nums.length) {
            ans.add(new ArrayList<>(currAns));
            return;
        }

        currAns.add(nums[idx++]);
        fn(idx);
        currAns.remove(currAns.size()-1);
        fn(idx);
    }

    public List<List<Integer>> subsets(int[] nums) {
        this.nums = nums;
        this.currAns = new ArrayList<>();
        this.ans = new ArrayList<>();
        fn(0);
        return ans;
    }
}
