/*
Time Complexity:
    - First binary search over rows: O(log m), where m = number of rows
    - Second binary search over columns: O(log n), where n = number of columns
    - Total: O(log m + log n)

Space Complexity:
    - O(1) extra space (only constant variables used)
*/

#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()-1, m, lowerIdx;

        while(l<=r) {
            m = l+(r-l)/2;
            if(target >= matrix[m][0]) {
                lowerIdx = m;
                l = m+1;
            } else r = m-1;
        }

        l = 0; r = matrix[lowerIdx].size()-1;

        while(l<=r) {
            m = l + (r-l)/2;

            if(target > matrix[lowerIdx][m]) l = m+1;
            else if(target < matrix[lowerIdx][m]) r = m-1;
            else return true;
        }

        return false;
    }
};
