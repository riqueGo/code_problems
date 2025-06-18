package insert_interval;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ans = new ArrayList<>();

        int i = 0;
        for(; i < intervals.length && newInterval[0] > intervals[i][1]; i++) {
            ans.add(intervals[i]);
        }

        for(; i < intervals.length && newInterval[1] >= intervals[i][0]; i++) {
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
        }

        ans.add(newInterval);

        for(; i < intervals.length; i++) {
            ans.add(intervals[i]);
        }

        return ans.toArray(new int[ans.size()][]);
    }
}
