package largest_rectangle_in_histogram;

import java.util.Deque;
import java.util.ArrayDeque;

class Solution {
    public int largestRectangleArea(int[] heights) {
        if (heights.length == 1) return heights[0];

        int maxArea = 0;
        int height = 0, idx = 0;

        // Stack will store pairs: [index, height]
        Deque<int[]> stack = new ArrayDeque<>();
        stack.push(new int[]{0, heights[0]});

        for (int i = 1; i < heights.length; i++) {
            if (stack.peek()[1] <= heights[i]) {
                stack.push(new int[]{i, heights[i]});
                continue;
            }

            while (!stack.isEmpty() && stack.peek()[1] > heights[i]) {
                int[] top = stack.pop();
                idx = top[0];
                height = top[1];

                maxArea = Math.max(maxArea, height * (i - idx));
            }
            stack.push(new int[]{idx, heights[i]});
        }

        int maxWidth = heights.length;
        while (!stack.isEmpty()) {
            int[] top = stack.pop();
            idx = top[0];
            height = top[1];

            maxArea = Math.max(maxArea, height * (maxWidth - idx));
        }

        return maxArea;
    }
}

