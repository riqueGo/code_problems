/*
 * Time Complexity: O(N * M)
 *   - N is the number of rows, M is the number of columns.
 *   - Each element is visited exactly once.
 *
 * Space Complexity: O(N * M)
 *   - For the output vector containing all elements.
 */

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int columnEnd = matrix.size(),
            rowEnd = matrix[0].size(),
            columnStart = 0,
            rowStart = 0,
            idx = 0;

        vector<int> ans(columnEnd * rowEnd);

        while(columnStart < columnEnd || rowStart < rowEnd) {
            for(int i = rowStart; i < rowEnd; i++) ans[idx++] = matrix[columnStart][i];
            columnStart++;

            if(idx >= ans.size()) break;

            for(int i = columnStart; i < columnEnd; i++) ans[idx++] = matrix[i][rowEnd-1];
            rowEnd--;

            if(idx >= ans.size()) break;

            for(int i = rowEnd-1; i >= rowStart; i--) ans[idx++] = matrix[columnEnd-1][i];
            columnEnd--;

            if(idx >= ans.size()) break;

            for(int i = columnEnd-1; i >= columnStart; i--) ans[idx++] = matrix[i][rowStart];
            rowStart++;

            if(idx >= ans.size()) break;
        }

        return ans;
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> result = sol.spiralOrder(matrix);
    
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}