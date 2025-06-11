package majority_element;

class Solution {
    public int majorityElement(int[] nums) {
        int candidate = nums[0];
        int quantity = 1;
        for(int num : nums) {
            if(num == candidate) {
                quantity++;
                continue;
            }

            quantity--;
            if(quantity == 0) {
                candidate = num;
                quantity = 1;
            }
        }
        return candidate;
    }
}
