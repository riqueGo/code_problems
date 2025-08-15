package search_a_2d_matrix;

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int l = 0, r = matrix.length - 1, m = 0, lowerIdx = 0;

        while (l <= r) {
            m = l + (r - l) / 2;
            if (target >= matrix[m][0]) {
                lowerIdx = m;
                l = m + 1;
            } else r = m - 1;
        }

        l = 0; r = matrix[lowerIdx].length - 1;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (target > matrix[lowerIdx][m]) l = m + 1;
            else if (target < matrix[lowerIdx][m]) r = m - 1;
            else return true;
        }

        return false;
    }
}
