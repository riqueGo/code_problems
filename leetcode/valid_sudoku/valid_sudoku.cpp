/*
Time Complexity: O(81) ≈ O(1)
- Checking rows: 9 × 9 = 81 operations
- Checking columns: 9 × 9 = 81 operations
- Checking 3×3 sub-boxes: 9 × 9 = 81 operations
Total = 243 operations, constant time because board size is fixed (9×9)

Space Complexity: O(1)
- `visited` array of size 10 → constant
- No extra structures, just a few variables
*/

#include <vector>

using std::vector;

class Solution {
private:
    bool visited[10] = {false};

    void reset() {
        for (int i = 1; i < 10; ++i) visited[i] = false;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        char currVal;

        // Check rows
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                currVal = board[i][j];
                if (currVal == '.') continue;
                if (visited[currVal - '0']) return false;
                visited[currVal - '0'] = true;
            }
            reset();
        }

        // Check columns
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                currVal = board[j][i];
                if (currVal == '.') continue;
                if (visited[currVal - '0']) return false;
                visited[currVal - '0'] = true;
            }
            reset();
        }

        // Check 3x3 sub-boxes
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                for (int i = r * 3; i < r * 3 + 3; ++i) {
                    for (int j = c * 3; j < c * 3 + 3; ++j) {
                        currVal = board[i][j];
                        if (currVal == '.') continue;
                        if (visited[currVal - '0']) return false;
                        visited[currVal - '0'] = true;
                    }
                }
                reset();
            }
        }

        return true;
    }
};
