package gas_station;

class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total = 0, tank = 0, start = 0;

        for (int i = 0; i < gas.length; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;

            if (tank < 0) {
                start = i + 1; // reset start
                tank = 0;      // reset tank
            }
        }

        return total >= 0 ? start : -1;
    }
}