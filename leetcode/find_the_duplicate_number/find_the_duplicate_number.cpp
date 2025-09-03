/*
 * Time Complexity: O(N)
 *   - N is the number of elements in the array.
 *   - Both the slow and fast pointers traverse the list at most twice.
 *
 * Space Complexity: O(1)
 *   - Uses only constant extra space for pointers.
 */

#include <vector>

using std::vector;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};