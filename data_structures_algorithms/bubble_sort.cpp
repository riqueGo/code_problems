#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::swap;
using std::cout;
using std::endl;

/*
 Bubble Sort:
 ------------
 - Bubble Sort is a simple comparison-based sorting algorithm.
 - It works by repeatedly swapping adjacent elements if they are in the wrong order.
 - After each pass, the largest element among the unsorted part "bubbles up" to its correct position.

 Steps:
 ------
 1. Repeat for n-1 passes:
    - Compare adjacent elements.
    - If arr[j] > arr[j+1], swap them.
 2. After the i-th pass, the last i elements are already sorted, so the inner loop goes up to n-i-1.

 Time Complexity:
 ----------------
 - Worst Case: O(n²) (when the array is in reverse order)
 - Best Case: O(n) (when the array is already sorted, using an optimization)
 - Space Complexity: O(1) (in-place)

 Stable? Yes (does not change relative order of equal elements)
*/

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    // Outer loop for passes
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Last i elements are already sorted, so no need to check them
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Optimization: if no swaps occurred in this pass, array is sorted
        if (!swapped) break;
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}

/*
 Example Output:
 ---------------
 Original array: 64 34 25 12 22 11 90
 Sorted array:   11 12 22 25 34 64 90
*/