package pacific_atlantic_water_flow;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;

class Solution {
    private boolean isOutOfBounds(int i, int j, int m, int n) {
        return i < 0 || j < 0 || i >= m || j >= n;
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int m = heights.length;
        int n = heights[0].length;
        int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        String[][] aux = new String[m][n];
        for (int i = 0; i < m; i++) Arrays.fill(aux[i], "");

        Deque<int[]> coord = new ArrayDeque<>();

        for (int j = 0; j < n; j++) coord.push(new int[]{0, j});
        for (int i = 0; i < m; i++) coord.push(new int[]{i, 0});

        while (!coord.isEmpty()) {
            int[] top = coord.pop();
            int i = top[0], j = top[1];

            if (!aux[i][j].equals("")) continue;
            aux[i][j] = "P";

            for (int[] d : dir) {
                int x = i + d[0];
                int y = j + d[1];

                if (!isOutOfBounds(x, y, m, n) && !aux[x][y].equals("P") && heights[x][y] >= heights[i][j]) {
                    coord.push(new int[]{x, y});
                }
            }
        }

        for (int j = 0; j < n; j++) coord.push(new int[]{m - 1, j});
        for (int i = 0; i < m; i++) coord.push(new int[]{i, n - 1});

        while (!coord.isEmpty()) {
            int[] top = coord.pop();
            int i = top[0], j = top[1];

            if (aux[i][j].equals("A") || aux[i][j].equals("PA")) continue;
            aux[i][j] += "A";

            for (int[] d : dir) {
                int x = i + d[0];
                int y = j + d[1];

                if (!isOutOfBounds(x, y, m, n) && !aux[x][y].equals("A") && !aux[x][y].equals("PA") && heights[x][y] >= heights[i][j]) {
                    coord.push(new int[]{x, y});
                }
            }
        }

        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (aux[i][j].equals("PA")) {
                    ans.add(Arrays.asList(i, j));
                }
            }
        }

        return ans;
    }
}
