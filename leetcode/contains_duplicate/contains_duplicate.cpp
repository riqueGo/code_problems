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