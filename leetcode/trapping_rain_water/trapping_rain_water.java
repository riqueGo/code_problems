package trapping_rain_water;

class Solution {
    public int trap(int[] height) {
        int n = height.length;
        if (n <= 2) return 0;

        int[] maxL = new int[n];
        int[] maxR = new int[n];

        int l = 0, r = n - 1;
        maxL[l] = height[l];
        maxR[r] = height[r];
        l++; r--;

        while (l < n) {
            maxL[l] = Math.max(height[l], maxL[l - 1]);
            maxR[r] = Math.max(height[r], maxR[r + 1]);
            l++;
            r--;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += Math.min(maxL[i], maxR[i]) - height[i];
        }

        return ans;
    }
}
