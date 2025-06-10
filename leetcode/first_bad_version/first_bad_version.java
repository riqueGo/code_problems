package first_bad_version;

/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

class VersionControl{
    public boolean isBadVersion(int x) {
        return true; // leetcode implemented
    }
}

class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left = 1, right = n, mid = 1, badVersion = 1;
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
}