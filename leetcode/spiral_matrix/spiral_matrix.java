package spiral_matrix;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int rowStart = 0,
            rowEnd = matrix.length,
            colStart = 0, 
            colEnd = matrix[0].length,
            allValues = rowEnd * colEnd;

        while(colStart < colEnd || rowStart < rowEnd) {
            for(int col = colStart; col < colEnd; col++) ans.add(matrix[rowStart][col]);
            rowStart++;

            if(ans.size() >= allValues) break;

            for(int row = rowStart; row < rowEnd; row++) ans.add(matrix[row][colEnd-1]);
            colEnd--;

            if(ans.size() >= allValues) break;

            for(int col = colEnd-1; col >= colStart; col--) ans.add(matrix[rowEnd-1][col]);
            rowEnd--;

            if(ans.size() >= allValues) break;

            for(int row = rowEnd-1; row >= rowStart; row--) ans.add(matrix[row][colStart]);
            colStart++;

            if(ans.size() >= allValues) break;
        }

        return ans;
    }
}
