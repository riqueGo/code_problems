/*
 * Time Complexity: O(log N)
 *   - N is the number of versions.
 *   - Each iteration halves the search space.
 *
 * Space Complexity: O(1)
 *   - Only a constant amount of extra space is used.
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version) {return true;}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid, badVersion;
        while(left <= right) {
            mid = left+(right-left)/2;
            if(isBadVersion(mid)) {
                badVersion = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return badVersion;
    }
};