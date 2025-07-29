/*
 * Time Complexity: O(N)
 *   - N is the length of the array.
 *
 * Space Complexity: O(1)
 */

#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1, ans = 0;

        while(l < r) {
            ans = max(ans, (r-l) * (min(height[l], height[r])));
            
            if(height[l] > height[r]) r--;
            else l++;
        }
        return ans;
    }
};