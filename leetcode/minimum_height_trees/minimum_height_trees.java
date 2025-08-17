package minimum_height_trees;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n == 1) return Collections.singletonList(0);

        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        int[] degree = new int[n];
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
            degree[u]++;
            degree[v]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.offer(i);
            }
        }

        int remainLeaves = n;
        while (remainLeaves > 2) {
            int leavesToRemove = q.size();
            for (int i = 0; i < leavesToRemove; i++) {
                int leaf = q.poll();
                for (int neighbor : graph.get(leaf)) {
                    if (--degree[neighbor] == 1) {
                        q.offer(neighbor);
                    }
                }
            }
            remainLeaves -= leavesToRemove;
        }

        List<Integer> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            ans.add(q.poll());
        }

        return ans;
    }
}
