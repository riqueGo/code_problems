/*
 * Time Complexity: O(N)
 *   - N is the number of pixels in the image.
 *   - Each pixel is visited at most once.
 *
 * Space Complexity: O(N)
 *   - Due to recursion stack or queue in BFS/DFS.
 */

#include<iostream>
#include<vector>

using std::vector;

class Solution {
private:
    int rowSize;
    int columnSize;
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int source = image[sr][sc];

        if(source == color) return image;

        image[sr][sc] = color;
        columnSize = image.size();
        rowSize = image[0].size();

        dfs(image, sr, sc, color, source);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int source) {
        int x,y;
        for(int i = 0; i < 4; i++) {
            x = sr + dir[i][0];
            y = sc + dir[i][1];
            if(isOutOfEdges(x,y)) continue;
            if(image[x][y] == source) {
                image[x][y] = color;
                dfs(image, x, y, color, source);
            }
        }
    }

    bool isOutOfEdges(int sr, int sc) {
        return sr < 0 || sc < 0 || sr >= columnSize || sc >= rowSize;
    }
};

int main() {
    vector<vector<int>> image = {
        {0,0,0},
        {0,0,0}
    };
    Solution s;
    s.floodFill(image, 1, 0, 2);
}