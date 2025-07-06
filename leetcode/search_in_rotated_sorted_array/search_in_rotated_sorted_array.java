package search_in_rotated_sorted_array;

class Solution {
    public int search(int[] nums, int target) {
        int l = 0, m, r = nums.length-1;

        while(l <= r) {
            m = l + ((r-l)/2);
            
            if(nums[m] == target) return m;
            else if(nums[l] <= nums[m]) {
                if(target > nums[m] || target < nums[l]) l = m+1;
                else r = m-1;
            } else {
                if(target < nums[m] || target > nums[r]) r = m-1;
                else l = m+1;
            }
        }
        return -1;
    }
}
