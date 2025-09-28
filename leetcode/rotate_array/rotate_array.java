package rotate_array;

class Solution {
    // O(n) extra space solution
    public void rotate(int[] nums, int k) {
        if (nums.length == 0) return;
        k %= nums.length;
        if (k == 0) return;

        int n = nums.length;
        int[] ans = new int[n];

        // Copy last k elements
        System.arraycopy(nums, n - k, ans, 0, k);
        // Copy first n-k elements
        System.arraycopy(nums, 0, ans, k, n - k);

        // Copy back into nums
        System.arraycopy(ans, 0, nums, 0, n);
    }

    // In-place O(1) space solution
    public void inPlace(int[] nums, int k) {
        if (nums.length == 0) return;
        k %= nums.length;
        if (k == 0) return;

        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }

    private void reverse(int[] nums, int left, int right) {
        while (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
}
