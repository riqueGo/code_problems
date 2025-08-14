package maximum_profit_in_job_scheduling;

import java.util.Arrays;

class Solution {
    private int fn(int i, int[][] jobs, int[] cache) {
        if (i == jobs.length) return 0;

        if (cache[i] != -1) return cache[i];

        int ans = fn(i + 1, jobs, cache);

        int l = i + 1, r = jobs.length, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (jobs[m][0] >= jobs[i][1]) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        cache[i] = Math.max(ans, jobs[i][2] + fn(r, jobs, cache));
        return cache[i];
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = profit.length;
        int[][] jobs = new int[n][3];
        int[] cache = new int[n];
        Arrays.fill(cache, -1);

        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        Arrays.sort(jobs, (a, b) -> Integer.compare(a[0], b[0]));
        return fn(0, jobs, cache);
    }
}