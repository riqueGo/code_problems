#include <vector>
#include <iostream>
#include <climits>

using std::vector;
using std::max;
using std::cout;

/*
 Kadane's Algorithm:
 --------------------
 - Kadane’s algorithm is used to find the **maximum sum subarray** in an array of integers.
 - It works in O(n) time using dynamic programming (or a simple running sum approach).

 Steps:
 ------
 1. Initialize:
    - currentSum = 0
    - maxSum = INT_MIN (or arr[0] for a variation)
 2. Traverse array:
    - Add current element to currentSum.
    - If currentSum > maxSum, update maxSum.
    - If currentSum < 0, reset currentSum to 0 (because negative sum can't help future sums).
 3. Return maxSum.

 Time Complexity: O(n)
 Space Complexity: O(1)

 Handles:
 --------
 - Works for arrays with all negative numbers if we initialize maxSum properly.

 Variants:
 ---------
 - To also return the subarray, keep track of start and end indices.
*/

int kadaneMaxSubarraySum(vector<int>& arr) {
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int x : arr) {
        currentSum += x;
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0) currentSum = 0;
    }

    return maxSum;
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    int maxSum = kadaneMaxSubarraySum(arr);
    cout << "Maximum Subarray Sum: " << maxSum << "\n";

    return 0;
}

/*
 Example Output:
 ---------------
 Array: -2 -3 4 -1 -2 1 5 -3
 Maximum Subarray Sum: 7
 Max Sum: 7 from index 2 to 6
*/