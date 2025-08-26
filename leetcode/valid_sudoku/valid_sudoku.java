package valid_sudoku;

class Solution {
    private boolean[] visited = new boolean[10];

    private void reset() {
        for (int i = 1; i < 10; i++) {
            visited[i] = false;
        }
    }

    public boolean isValidSudoku(char[][] board) {
        char currVal;

        // Check rows
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                currVal = board[i][j];
                if (currVal == '.') continue;
                int num = currVal - '0';
                if (visited[num]) return false;
                visited[num] = true;
            }
            reset();
        }

        // Check columns
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                currVal = board[j][i];
                if (currVal == '.') continue;
                int num = currVal - '0';
                if (visited[num]) return false;
                visited[num] = true;
            }
            reset();
        }

        // Check 3x3 sub-boxes
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                for (int i = r * 3; i < r * 3 + 3; i++) {
                    for (int j = c * 3; j < c * 3 + 3; j++) {
                        currVal = board[i][j];
                        if (currVal == '.') continue;
                        int num = currVal - '0';
                        if (visited[num]) return false;
                        visited[num] = true;
                    }
                }
                reset();
            }
        }

        return true;
    }
}
