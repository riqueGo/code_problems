#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

class Solution {
public:
    // O(n) extra space solution
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k %= nums.size();
        if (k == 0) return;

        vector<int> ans;
        ans.insert(ans.end(), nums.end() - k, nums.end());
        ans.insert(ans.end(), nums.begin(), nums.end() - k);
        nums = std::move(ans);
    }

    // In-place O(1) space solution
    void inPlace(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k %= nums.size();
        if (k == 0) return;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
