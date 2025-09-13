/*
 * Time Complexity: O(N)
 *   - N is the number of elements in the array.
 *   - Both the slow and fast pointers traverse the sequence a constant number of times (linear).
 *
 * Space Complexity: O(1)
 *   - Uses only constant extra space for pointers.
 *
 * Why this works (Pigeonhole Principle + functional graph view):
 * -------------------------------------------------------------
 * - The array values are in the range [1..n] and there are n+1 elements.
 *   By the pigeonhole principle, at least one value appears more than once (a duplicate).
 *
 * - View the array as a function f from indices to indices: f(i) = nums[i].
 *   Starting from index 0 we generate the sequence:
 *     x0 = nums[0], x1 = nums[x0], x2 = nums[x1], ...
 *   Because values come from a finite set {1..n}, this sequence must eventually repeat,
 *   which means there is a cycle in the functional graph defined by f.
 *
 * - The duplicate value corresponds to the entry point of that cycle (the node that has
 *   multiple incoming edges). Floyd's Tortoise and Hare (slow/fast pointers) detects that cycle:
 *     * slow advances by one step: slow = f(slow)
 *     * fast advances by two steps: fast = f(f(fast))
 *   They will meet inside the cycle.
 *
 * - After the first meeting, resetting slow to the start and advancing both pointers one step
 *   at a time causes them to meet at the cycle entry point, which is the duplicate value.
 *
 * Notes:
 * - This method does not modify the input array and uses constant extra space.
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