package bus_routes;

import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) return 0;

        int n = routes.length;
        if (n == 0) return -1;

        Map<Integer, List<Integer>> busByStops = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                busByStops.computeIfAbsent(stop, k -> new ArrayList<>()).add(i);
            }
        }

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{source, 0}); // {stop, distance}
        
        Set<Integer> visitedBuses = new HashSet<>();
        Set<Integer> visitedStops = new HashSet<>();
        
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currStop = current[0];
            int currDist = current[1];

            if (currStop == target) return currDist;

            visitedStops.add(currStop);
            for (int bus : busByStops.getOrDefault(currStop, new ArrayList<>())) {
                if (visitedBuses.contains(bus)) continue;
                visitedBuses.add(bus);

                for (int stop : routes[bus]) {
                    if (!visitedStops.contains(stop)) {
                        queue.offer(new int[]{stop, currDist + 1});
                    }
                }
            }
        }

        return -1;
    }
    
}
