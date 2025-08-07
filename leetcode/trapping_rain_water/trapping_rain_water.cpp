/*
 * Time Complexity: O(N)
 *   - N is the length of the `height` array.
 *   - One pass to fill maxL and maxR arrays, and one pass to compute the result.
 *
 * Space Complexity: O(N)
 *   - Two additional arrays `maxL` and `maxR` of size N are used.
 *   - Could be optimized to O(1) space using two-pointer technique.
 */

#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;

        vector<int> maxL(n), maxR(n);

        int l = 0, r = n-1;
        maxL[l] = height[l];
        maxR[r] = height[r];
        l++; r--;

        while(l < n) {
            maxL[l] = max(height[l], maxL[l-1]);
            maxR[r] = max(height[r], maxR[r+1]);

            l++; r--;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += min(maxL[i], maxR[i]) - height[i];
        }

        return ans;
    }

    int alternativeTwoPointersSolution(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;

        int l = 0, r = n - 1;
        int maxL = height[l], maxR = height[r];
        int ans = 0;

        while(l < r) {
            if(maxL < maxR) {
                l++;
                maxL = max(maxL, height[l]);
                ans += maxL - height[l];
            } else {
                r--;
                maxR = max(maxR, height[r]);
                ans += maxR - height[r];
            }
        }

        return ans;
    }
};