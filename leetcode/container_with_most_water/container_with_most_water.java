package container_with_most_water;

class Solution {
    public int maxArea(int[] height) {
        int l = 0, r = height.length - 1, maxArea = 0;

        while (l < r) {
            maxArea = Math.max(maxArea, (r-l) * Math.min(height[l], height[r]));

            if (height[l] > height[r]) r--;
            else l++;
        }

        return maxArea;
    }
}
