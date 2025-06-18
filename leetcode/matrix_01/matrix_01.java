package matrix_01;

import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private Queue<int[]> visiting;
    private int columnLength;
    private int rowLength;
    private int[][] dir = {{-1,0},{0,1},{1,0},{0,-1}};
    private int[][] mat;

    public int[][] updateMatrix(int[][] mat) {
        this.mat = mat;
        columnLength = mat.length;
        rowLength = mat[0].length;
        visiting = new LinkedList<>();
        for(int i = 0; i < columnLength; i++) {
            for(int j = 0; j < rowLength; j++) {
                if(mat[i][j] == 1) {
                    mat[i][j] = Integer.MAX_VALUE;
                    if(hasZeroAround(i,j)) {
                        visiting.add(new int[]{i,j});
                    }
                }
            }
        }

        int[] pos;
        while(!visiting.isEmpty()) {
            pos = visiting.remove();
            attatchMinDist(pos[0], pos[1]);
        }
        return mat;
    }

    private void attatchMinDist(int i , int j) {
        int x,y;
        for(int k = 0; k < 4; k++) {
            x = dir[k][0] + i;
            y = dir[k][1] + j;
            if(isOutOfBounds(x,y)) continue;

            if(mat[x][y] == Integer.MAX_VALUE) {
                visiting.add(new int[]{x,y});
            } else {
                mat[i][j] = Math.min(mat[i][j], mat[x][y] + 1);
            }
        }
    }

    private boolean hasZeroAround(int i, int j) {
        int x,y;
        for(int k = 0; k < 4; k++) {
            x = dir[k][0] + i;
            y = dir[k][1] + j;
            if(!isOutOfBounds(x,y) && mat[x][y] == 0) return true;
        }
        return false;
    }

    private boolean isOutOfBounds(int i, int j) {
        return i < 0 || j < 0 || i >= columnLength || j >= rowLength;
    }
}
