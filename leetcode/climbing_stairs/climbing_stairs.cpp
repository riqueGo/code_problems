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