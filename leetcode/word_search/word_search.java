package word_search;

class Solution {

    private final int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    private int rowSize;
    private int colSize;
    private String word;
    private char[][] board;

    private boolean isOutOfBounds(int i, int j) {
        return i < 0 || j < 0 || i >= rowSize || j >= colSize;
    }

    private boolean dfs(int i, int j, int idx) {
        if (board[i][j] != word.charAt(idx)) return false;
        else if (idx + 1 == word.length()) return true;

        board[i][j] = '0';

        for (int[] d : dir) {
            int x = i + d[0];
            int y = j + d[1];

            if (!isOutOfBounds(x, y) && dfs(x, y, idx + 1)) return true;
        }

        board[i][j] = word.charAt(idx);
        return false;
    }

    public boolean exist(char[][] board, String word) {
        rowSize = board.length;
        colSize = board[0].length;
        this.word = word;
        this.board = board;

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (dfs(i, j, 0)) return true;
            }
        }

        return false;
    }
}