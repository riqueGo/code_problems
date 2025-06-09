package flood_fill;

class Solution {
    private int rowSize;
    private int columnSize;
    private int source;
    private int color;
    private int[][] dir = {{-1,0},{0,1},{1,0},{0,-1}};

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        source = image[sr][sc];
        if(source == color) return image;
        
        image[sr][sc] = color;
        this.color = color;
        rowSize = image[0].length;
        columnSize = image.length;


        dfs(image, sr, sc);
        return image;
    }

    private void dfs(int[][] image, int sr, int sc) {
        int x,y;
        for(int i = 0; i < 4; i++) {
            x = sr + dir[i][0];
            y = sc + dir[i][1];

            if(isOutOfEdges(x, y)) continue;
            if(image[x][y] == source) {
                image[x][y] = color;
                dfs(image, x, y);
            }
        }
    }

    private boolean isOutOfEdges(int sr, int sc) {
        return sr < 0 || sc < 0 || sr >= columnSize || sc >= rowSize;
    }

    public static void main(String[] args) {
        int[][] image = {
            {0,0,0},
            {0,1,0}
        };
        new Solution().floodFill(image, 1, 1, 2);
    }
}
