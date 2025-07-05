package rotting_oranges;

import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private class Position {
        public int i;
        public int j;
        Position(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }

    private int[][] dir = {{-1,0},{0,1},{1,0},{0,-1}};
    private int[][] grid;
    private int rowSize;
    private int columnSize;

    private boolean outOfBoundries(int i, int j) {
        return i < 0 || j < 0 || i >= columnSize || j >= rowSize;
    }

    private boolean impossibleToRot(int i, int j) {
        int x, y;
        for(int k = 0; k < 4; k++) {
            x = dir[k][0] + i;
            y = dir[k][1] + j;
            if(!outOfBoundries(x,y) && grid[x][y] != 0) return false;
        }
        
        return true;
    }

    public int orangesRotting(int[][] grid) {
        this.grid = grid;
        this.rowSize = grid[0].length;
        this.columnSize = grid.length;
        Queue<Position> q = new LinkedList<>();
        int freshOranges = 0;

        for(int i = 0; i < columnSize; i++) {
            for(int j = 0; j < rowSize; j++) {
                if(grid[i][j] == 1) {
                    freshOranges++;
                    if(impossibleToRot(i,j)) return -1;
                }
                if(grid[i][j] == 2) q.add(new Position(i,j));
            }
        }

        if(q.isEmpty()) return freshOranges == 0 ? 0 : -1;

        int minutes = -1;
        int level = q.size();
        int i, j, x, y;

        while(!q.isEmpty()) {
            i = q.peek().i;
            j = q.peek().j;
            q.remove();
            
            for(int k = 0; k < 4; k++) {
                x = dir[k][0] + i;
                y = dir[k][1] + j;
                if(!outOfBoundries(x,y) && grid[x][y] == 1) {
                    grid[x][y] = 2;
                    freshOranges--;
                    q.add(new Position(x,y));
                }
            }

            if(--level == 0) {
                minutes++;
                level = q.size();
            }
        }

        return freshOranges > 0 ? -1 : minutes;
    }
}
