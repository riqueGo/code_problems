/*
 * Time Complexity: O(N)
 *   - Each element is inserted and checked in the set once.
 *
 * Space Complexity: O(N)
 *   - In the worst case, all elements are unique and stored in the set.
 */

#include<unordered_set>
#include<vector>

using std::unordered_set;
using std::vector;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dist;
        for(int num : nums) {
            if(dist.find(num) != dist.end()) return true;
            dist.insert(num);
        }
        return false;
    }
};