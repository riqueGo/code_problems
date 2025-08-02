/*
 * Time Complexity: O(N * M * 4^L)
 *   - N is the number of rows, M is the number of columns.
 *   - L is the length of the word.
 *   - We start a DFS from each cell: O(N * M) calls.
 *   - Each DFS can explore up to 4 directions per letter, so in worst case O(4^L) paths.
 *
 * Space Complexity: O(L)
 *   - Due to the recursion stack, the maximum depth is the length of the word (L).
 *   - No additional data structures beyond recursion and constant space mutation.
 */

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
private:
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int columnSize;
    int rowSize;

    bool isOutOfBounds(int i, int j) {
        return i < 0 || j < 0 || i >= columnSize || j >= rowSize;
    }

    bool fn(vector<vector<char>>& board, const string& word, int i, int j, int idxWord) {
        if (board[i][j] != word[idxWord]) return false;
        else if(idxWord+1 == word.size()) return true;

        board[i][j] = '0';

        int x, y;
        for(int k = 0; k < 4; k++) {
            x = dir[k][0] + i;
            y = dir[k][1] + j;

            if(!isOutOfBounds(x,y) && fn(board, word, x, y, idxWord+1)) return true;
        }

        board[i][j] = word[idxWord];
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        columnSize = board.size();
        rowSize = board[0].size();

        for(int i = 0; i < columnSize; i++) {
            for(int j = 0; j < rowSize; j++) {
                if(fn(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};