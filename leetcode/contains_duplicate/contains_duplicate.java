package contains_duplicate;

import java.util.HashSet;

class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> dist = new HashSet<>();
        for(int num : nums) {
            if(dist.contains(num)) return true;
            dist.add(num);
        }
        return false;
    }
}
