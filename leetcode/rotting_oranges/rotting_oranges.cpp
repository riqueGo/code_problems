#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;

class Solution {
private:
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int rowSize;
    int columnSize;

    bool outOfBoundries(int i, int j) {
        return i < 0 || j < 0 || i >= columnSize || j >= rowSize;
    }

    bool impossibleToRot(vector<vector<int>>& grid, int i , int j) {
        int x, y;
        for(int k = 0; k < 4; k++) {
            x = dir[k][0] + i;
            y = dir[k][1] + j;
            if(!outOfBoundries(x,y) && grid[x][y] != 0) return false;
        }

        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        rowSize = grid[0].size();
        columnSize = grid.size();
        queue<pair<int,int>> q;
        int freshOranges = 0;
        
        for(int i = 0; i < columnSize; i++) {
            for(int j = 0; j < rowSize; j++) {
                if(grid[i][j] == 1) {
                    if(impossibleToRot(grid, i, j)) return -1;
                    freshOranges++;
                } else if(grid[i][j] == 2) q.push({i,j});
            }
        }

        if(q.empty()) return freshOranges == 0 ? 0 : -1;
        int i, j, x, y, level = q.size(), minutes = -1;

        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {
                x = dir[k][0] + i;
                y = dir[k][1] + j;
                if(!outOfBoundries(x,y) && grid[x][y] == 1) {
                    grid[x][y] = 2;
                    freshOranges--;
                    q.push({x,y});
                }
            }

            if(--level == 0) {
                minutes++;
                level = q.size();
            }
        }

        return freshOranges > 0 ? -1 : minutes;
    }
};