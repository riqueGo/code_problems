package number_of_islands;

class Solution {

    private int[][] dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    private int rowSize;
    private int columnSize;
    private char[][] grid;

    private boolean outOfBoundries(int i, int j) {
        return i < 0 || j < 0 || i >= columnSize || j >= rowSize;
    }

    private void dfs(int i, int j) {
        grid[i][j] = '2';
        int x, y;

        for(int k = 0; k < 4; k++) {
            x = dir[k][0] + i;
            y = dir[k][1] + j;
            if(!outOfBoundries(x,y) && grid[x][y] == '1') dfs(x,y);
        }
    }

    public int numIslands(char[][] grid) {
        rowSize = grid[0].length;
        columnSize = grid.length;
        this.grid = grid;
        int islands = 0;

        for(int i = 0; i < columnSize; i++) {
            for(int j = 0; j < rowSize; j++) {
                if(grid[i][j] == '1') {
                    dfs(i,j);
                    islands++;
                }
            }
        }

        return islands;
    }
}
