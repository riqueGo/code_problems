#include<vector>
#include<queue>
#include <climits>
#include <algorithm>

using std::vector;
using std::queue;
using std::pair;
using std::min;

class Solution {
private:
    int columnLength;
    int rowLength;
    int dir [4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    queue<pair<int,int>> visiting;

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        columnLength = mat.size();
        rowLength = mat[0].size();

        for(int i = 0; i < columnLength; i++) {
            for(int j = 0; j < rowLength; j++) {
                if(mat[i][j] == 1) {
                    mat[i][j] = INT_MAX;
                    if(hasZeroAround(mat, i,j)) {
                        visiting.push({i,j});
                    }
                }
            }
        }

        pair<int,int> pos;
        while(!visiting.empty()) {
            pos = visiting.front();
            visiting.pop();
            attachMinDist(mat, pos.first, pos.second);
        }

        return mat;
    }

    void attachMinDist(vector<vector<int>>& mat, int i, int j) {
        int x,y;
        for(int k = 0; k < 4; k++) {
            x = dir[k][0] + i;
            y = dir[k][1] + j;
            if(isOutOfEdges(x,y)) continue;
            if(mat[x][y] == INT_MAX) {
                visiting.push({x,y});
            } else {
                mat[i][j] = min(mat[i][j], mat[x][y]+1);
            }
        }
    }

    bool hasZeroAround(vector<vector<int>>& mat, int i, int j) {
        int x,y;
        for(int k = 0; k < 4; k++) {
            x = dir[k][0] + i;
            y = dir[k][1] + j;
            if(!isOutOfEdges(x,y) && mat[x][y] == 0) return true;
        }
        return false;
    }

    bool isOutOfEdges(int i, int j) {
        return i < 0 || j < 0 || i >= columnLength || j >= rowLength;
    }
};

int main() {
    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };
    Solution s;
    s.updateMatrix(mat);
}