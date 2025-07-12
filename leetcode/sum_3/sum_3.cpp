/*
 * Time Complexity: O(N^2)
 *   - N is the number of elements in the array.
 *   - Sorting is O(N log N), and for each element, a two-pointer scan is O(N).
 *
 * Space Complexity: O(M)
 *   - M is the number of unique triplets in the answer.
 *   - Additional space for sorting is O(1) or O(N) depending on implementation.
 */

#include <vector>
#include<algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int j, k, total;

        for(int i = 0; i < nums.size()-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            j = i+1;
            k = nums.size()-1;

            while(j < k) {
                total = nums[i] + nums[j] + nums[k];
                if(total < 0) j++;
                else if (total > 0) k--;
                else {
                    ans.push_back({nums[i], nums[j++], nums[k]});
                    while(nums[j] == nums[j-1] && j < k) j++;
                }
            }
        }

        return ans;
    }
};