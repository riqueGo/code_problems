package combination_sum;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {
    private int[] candidates;
    private List<List<Integer>> ans;
    private List<Integer> currAns;
    private int target;
    
    private boolean combination(int currSum, int currIndex) {
        if(currSum == target) {
            ans.add(new ArrayList<>(currAns));
            return true;
        }

        if(currIndex >= candidates.length) return false;

        int tmpCurrSum = currSum + candidates[currIndex];
        if(tmpCurrSum > target) return false;

        currAns.add(candidates[currIndex]);
        boolean first = combination(tmpCurrSum, currIndex);
        currAns.remove(currAns.size()-1);
        if(!first) combination(currSum, currIndex+1);

        return false;
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        this.candidates = candidates;
        this.target = target;
        this.ans = new LinkedList<>();
        this.currAns = new ArrayList<>();

        Arrays.sort(candidates);

        currAns.add(candidates[0]);
        combination(candidates[0], 0);
        currAns.remove(currAns.size()-1);
        combination(0, 1);

        return ans;
    }


}