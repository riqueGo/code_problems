/*
Time Complexity: O(n) → Single pass.
Space Complexity: O(1) → No extra memory used.
*/

#include<vector>

using std::vector;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, tank = 0, start = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            
            if (tank < 0) {
                start = i + 1; // reset start
                tank = 0;      // reset tank
            }
        }
        
        return (total >= 0) ? start : -1;
    }
};