/*
 * Time Complexity: O(N)
 *   - N is the number of steps.
 *   - Each step is computed once.
 *
 * Space Complexity: O(1)
 *   - Only a constant amount of extra space is used.
 */

class Solution {
public:
    int climbStairs(int n) {
        int x = 0, y = 1, tmp;
        for(int i = 0; i < n; i++){
            tmp = y;
            y += x;
            x = tmp;
        }
        return y;
    }
};