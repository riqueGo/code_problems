/*
    All functions below run in:
    - Time Complexity: O(log n) — binary search halves the range each iteration.
    - Space Complexity: O(1) — only a few variables, no extra arrays.

    Definitions:
    - binarySearch: Finds exact target index or returns -1.
    - lowerBoundBinarySearch: Finds index of greatest value <= target.
    - upperBoundBinarySearch: Finds index of smallest value >= target.
*/

#include<iostream>
#include <vector>

using std::vector;

// Standard binary search — exact match only
int binarySearch(const vector<int>& arr, const int target) {
    int left = 0, right = arr.size()-1, mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (target > arr[mid]) left = mid + 1;
        else if (target < arr[mid]) right = mid - 1;
        else return mid; // exact match
    }
    return -1; // not found
}

// Lower bound — greatest value <= target
int lowerBoundBinarySearch(const vector<int>& arr, const int target) {
    int left = 0, right = arr.size()-1, mid, lower = -1;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (target >= arr[mid]) { // candidate
            lower = mid;
            left = mid + 1; // search right for bigger candidate
        } else {
            right = mid - 1;
        }
    }
    return lower;
}

// Upper bound — smallest value >= target
int upperBoundBinarySearch(const vector<int>& arr, const int target) {
    int left = 0, right = arr.size()-1, mid = -1, upper = -1;

    while(left <= right) {
        mid = left + (right - left)/2;

        if(target > arr[mid]) left = mid + 1;
        else { // candidate
            upper = mid;
            right = mid - 1; // search left for smaller candidate
        }
    }

    return upper;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};

    // Test cases
    vector<int> targets = {7, 6, 0, 10, 5};

    for (int t : targets) {
        int bs = binarySearch(arr, t);
        int lb = lowerBoundBinarySearch(arr, t);
        int ub = upperBoundBinarySearch(arr, t);

        std::cout << "Target: " << t << "\n";
        std::cout << "  binarySearch: " << bs;
        if (bs != -1) std::cout << " (value=" << arr[bs] << ")";
        std::cout << "\n";

        std::cout << "  lowerBoundBinarySearch: " << lb;
        if (lb != -1) std::cout << " (value=" << arr[lb] << ")";
        std::cout << "\n";

        std::cout << "  upperBoundBinarySearch: " << ub;
        if (ub != -1) std::cout << " (value=" << arr[ub] << ")";
        std::cout << "\n\n";
    }
    return 0;
}