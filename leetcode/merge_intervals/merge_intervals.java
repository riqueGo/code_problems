package merge_intervals;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length < 2)
            return intervals;

        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));

        ArrayList<int[]> ans = new ArrayList<>();
        ans.add(intervals[0]);
        int i = 0, maxInterval, lastIndex;

        while (i < intervals.length) {
            lastIndex = ans.size() - 1;
            if (intervals[i][0] > ans.get(lastIndex)[1]) {
                ans.add(intervals[i++]);
            } else {
                maxInterval = ans.get(lastIndex)[1];
                while (i < intervals.length && intervals[i][0] <= maxInterval) maxInterval = Math.max(maxInterval, intervals[i++][1]);
                ans.get(lastIndex)[1] = maxInterval;
            }
        }
        return ans.toArray(new int[0][]);
    }
}
