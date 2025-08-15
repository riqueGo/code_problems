package koko_eating_bananas;

class Solution {
    private boolean canEat(int[] piles, int h, int k) {
        int hours = 0;
        for (int pile : piles) {
            hours += pile / k;
            if (pile % k != 0)hours++;
            if (hours > h) return false;
        }
        return hours <= h;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int r = -1;
        for (int pile : piles) r = Math.max(r, pile);

        int l = 1, m, ans = r;
        while (l <= r) {
            m = l + (r - l) / 2;

            if (canEat(piles, h, m)) {
                ans = m;
                r = m - 1;
            } else l = m + 1;
        }

        return ans;
    }
}

