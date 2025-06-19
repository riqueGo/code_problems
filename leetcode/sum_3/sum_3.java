package sum_3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        int j, k, total;

        for(int i = 0; i < nums.length - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            j = i+1;
            k = nums.length-1;
            while(j < k) {
                total = nums[i] + nums[j] + nums[k];
                if(total < 0) j++;
                else if (total > 0) k--;
                else {
                    ans.add(new ArrayList<>(List.of(nums[i], nums[j++], nums[k])));
                    while(j < k && nums[j] == nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
}