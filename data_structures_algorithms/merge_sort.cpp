#include <vector>
#include <iostream>
#include<algorithm>

using std::vector;
using std::min;
using std::cout;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;

    vector<int>left(n1), right(n2);
    for(int i = 0; i < n1; i++) left[i] = arr[l+i];
    for(int i = 0; i < n2; i++) right[i] = arr[m+i+1];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];
}


/*
 Merge Sort (Recursive):
 ------------------------
 - Merge Sort is a divide-and-conquer algorithm:
   1. Divide the array into two halves.
   2. Recursively sort each half.
   3. Merge the two sorted halves.

 - Time Complexity: O(n log n) in all cases.
 - Space Complexity: O(n) because of temporary arrays during merging.
 - Stable: Yes.
*/

void mergeSortRecursive(vector<int>& arr, int l, int r) {
    if(l >= r) return;
    int m = l+ (r-l)/2;
    mergeSortRecursive(arr, l, m);
    mergeSortRecursive(arr, m+1, r);
    merge(arr, l, m, r);
}

/*
 Iterative Merge Sort:
 ----------------------
 - Instead of recursion, we start with subarrays of size 1 and iteratively merge them.
 - Double the subarray size on each pass: 1 -> 2 -> 4 -> 8 ...
*/

void mergeSortIterative(vector<int>& arr) {
    int n = arr.size();

    for(int currSize = 1; currSize < n; currSize *= 2) {
        for(int left = 0; left < n-1; left += 2*currSize) {
            int mid = min(left + currSize-1, n-1);
            int right = min(left + 2*currSize - 1, n-1);

            if(mid < right) merge(arr, left, mid, right);
        }
    }
}

void inPlaceMerge(vector<int>& arr, int l, int m, int r) {
    int start2 = m+1;

    if(arr[m] <= arr[start2]) return;

    while(l <= m && start2 <= r) {
        if(arr[l] <= arr[start2]) {
            l++;
            continue;
        }

        int value = arr[start2];
        int index = start2;

        while(index != l) {
            arr[index] = arr[index-1];
            index--;
        }
        arr[l] = value;

        l++; m++; start2++;
    }
}

/*
 In-place Merge Sort:
 ---------------------
 - Merge two sorted subarrays within the same array without extra arrays.
 - Use element rotation to insert elements in order.
*/

void mergeSortInPlace(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortInPlace(arr, l, m);
    mergeSortInPlace(arr, m + 1, r);
    inPlaceMerge(arr, l, m, r);
}



int main() {
    vector<int> arr1 = {38, 27, 43, 3, 9, 82, 10};
    vector<int> arr2 = arr1;
    vector<int> arr3 = arr1;

    cout << "Original: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n";

    mergeSortRecursive(arr1, 0, arr1.size() - 1);
    cout << "Recursive Merge Sort: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n";

    mergeSortIterative(arr2);
    cout << "Iterative Merge Sort: ";
    for (int x : arr2) cout << x << " ";
    cout << "\n";

    mergeSortInPlace(arr3, 0, arr3.size() - 1);
    cout << "In-Place Merge Sort: ";
    for (int x : arr3) cout << x << " ";
    cout << "\n";

    return 0;
}
