#include <vector>

using std::vector;

class Solution {
private:
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int rowSize;
    int columnSize;

    bool outOfBoundries(int i, int j) {
        return i < 0 || j < 0 || i >= columnSize || j >= rowSize;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '2';
        int x,y; 

        for(int k = 0; k < 4; k++) {
            x = dir[k][0]+i;
            y = dir[k][1]+j;
            if(!outOfBoundries(x,y) && grid[x][y] == '1') dfs(grid, x, y);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        rowSize = grid[0].size();
        columnSize = grid.size();
        int island = 0;

        for(int i = 0; i < columnSize; i++) {
            for(int j = 0; j < rowSize; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    island++;
                }
            }
        }

        return island;
    }
};