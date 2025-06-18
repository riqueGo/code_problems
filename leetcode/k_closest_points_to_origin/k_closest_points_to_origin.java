package k_closest_points_to_origin;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
    class Point {
        private int x;
        private int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        int distanceSquare() {
            return x*x + y*y;
        }
    }

    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Point> pq = new PriorityQueue<>(
            (a,b) -> Integer.compare(b.distanceSquare(), a.distanceSquare())
        );

        for(int[] p : points) {
            pq.add(new Point(p[0], p[1]));
            if(pq.size() > k) {
                pq.poll();
            }
        }

        List<int[]> ans = new ArrayList<>();
        while(!pq.isEmpty()) {
            Point p = pq.poll();
            ans.add(new int[]{p.x, p.y});
        }

        return ans.toArray(new int[0][]);
    }
}