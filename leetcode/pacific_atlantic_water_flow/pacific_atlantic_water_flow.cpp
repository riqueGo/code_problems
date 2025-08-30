/*
 * Time Complexity: O(m * n), where m = number of rows and n = number of columns in heights.
 * Each cell is processed at most twice (once for Pacific, once for Atlantic), and each DFS/BFS traversal
 * visits neighbors in O(4) per cell. So overall O(m * n).
 *
 * Space Complexity: O(m * n) for the auxiliary matrix `aux` and the recursion/stack used for DFS traversal.
 * The stack can, in the worst case, hold all cells, so O(m * n).
 */

#include <vector>
#include <stack>
#include <string>

using std::vector;
using std::stack;
using std::pair;
using std::string;

class Solution {
private:
    bool isOutOfBounds(const int& i, const int& j, const int& m, const int& n) {
        return i < 0 || j < 0 || i >= m || j >= n;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int dir [4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        vector<vector<string>> aux(m, vector<string>(n, ""));
        stack<pair<int, int>> coord;

        for(int j = 0; j < n; j++) coord.push({0,j});
        for(int i = 0; i < m; i++) coord.push({i,0});

        while(!coord.empty()) {
            int i = coord.top().first;
            int j = coord.top().second;
            coord.pop();

            if(aux[i][j] != "") continue;
            aux[i][j] = "P";

            for(int k = 0; k < 4; k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];

                if(!isOutOfBounds(x, y, m, n) && aux[x][y] != "P" && heights[x][y] >= heights[i][j]) {
                    coord.push({x,y});
                }
            }
        }

        for(int j = 0; j < n; j++) coord.push({m-1,j});
        for(int i = 0; i < m; i++) coord.push({i,n-1});

        while(!coord.empty()) {
            int i = coord.top().first;
            int j = coord.top().second;
            coord.pop();

            if(aux[i][j] == "A" || aux[i][j] == "PA") continue;
            aux[i][j] += "A";

            for(int k = 0; k < 4; k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];

                if(!isOutOfBounds(x, y, m, n) && aux[x][y] != "A" && aux[x][y] != "PA" && heights[x][y] >= heights[i][j]) {
                    coord.push({x,y});
                }
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(aux[i][j] == "PA") ans.push_back({i,j});
            }
        }

        return ans;
    }
};