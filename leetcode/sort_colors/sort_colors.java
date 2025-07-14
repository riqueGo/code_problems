package sort_colors;

class Solution {
    public void sortColors(int[] nums) {
        int i = 0, l = 0, r = nums.length-1, tmp;

        while(i<=r) {
            if(nums[i] == 0) {
                tmp = nums[l];
                nums[l] = nums[i];
                nums[i] = tmp;
                i++; l++;
            } else if(nums[i] == 1)i++;
            else {
                tmp = nums[i];
                nums[i] = nums[r];
                nums[r--] = tmp;
            }
        }
    }
}
