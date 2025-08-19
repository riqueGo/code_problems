#include <bits/stdc++.h>
using namespace std;

/*
 Heap Data Structure:
 --------------------
 - A Heap is a complete binary tree that satisfies the heap property:
   * Min-Heap: The key at the root must be the minimum among all keys in the heap.
   * Max-Heap: The key at the root must be the maximum among all keys in the heap.
 - It is commonly implemented using an array.

 Representation (for array index 'i'):
 ------------------------------------
 - Left Child index  = 2*i + 1
 - Right Child index = 2*i + 2
 - Parent index      = (i-1)/2

 Common Operations:
 ------------------
 1. insert(x): Insert a new element into the heap and fix the heap property by "bubbling up".
 2. extractMin(): Remove the minimum element (root in Min-Heap), replace with the last element,
    and fix the heap property by "heapifying down".
 3. getMin(): Get the minimum element in O(1).
 4. heapify(i): Ensure the subtree rooted at index i satisfies the heap property.
 5. buildHeap(): Convert an arbitrary array into a valid heap in O(n).

 Time Complexities:
 ------------------
 - Insert: O(log n)
 - Extract Min/Max: O(log n)
 - Get Min/Max: O(1)
 - Build Heap: O(n)
*/

class MinHeap {
private:
    vector<int> heap; // underlying array to store elements

    // Heapify down: fix heap property starting from index i downwards
    void heapifyDown(int i) {
        int n = heap.size(), smallest, left, right;
        
        do {
            smallest = i;
            left = 2*i+1;
            right = 2*i+2;

            if(left < n && heap[left] < heap[smallest]) smallest = left;
            if(right < n && heap[right] < heap[smallest]) smallest = right;

            if(smallest != i) swap(heap[smallest], heap[i]);
            i = smallest;
        } while (smallest != i);
    }

    // Heapify up: fix heap property starting from index i upwards
    void heapifyUp(int i) {
        int parent = (i-1)/2;
        while(i > 0 && heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
            parent = (i-1)/2;
        }
    }

public:
    // Insert a new value into heap
    void insert(int val) {
        heap.emplace_back(val);
        heapifyUp(heap.size()-1);
    }

    // Get the minimum element (root)
    int getMin() {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        return heap[0];
    }

    // Extract and remove the minimum element
    int extractMin() {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if(!heap.empty()) heapifyDown(0);

        return root;
    }

    // Build heap from arbitrary array
    void buildHeap(vector<int>& arr) {
        heap = arr;
        for(int i = (heap.size()/2)-1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // Print heap (level-order)
    void printHeap() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

// Example usage
int main() {
    MinHeap h;

    // Insert elements
    h.insert(10);
    h.insert(5);
    h.insert(30);
    h.insert(2);
    h.insert(8);

    cout << "Heap after insertions: ";
    h.printHeap();

    cout << "Min element: " << h.getMin() << endl;

    cout << "Extracted Min: " << h.extractMin() << endl;

    cout << "Heap after extraction: ";
    h.printHeap();

    // Build heap from array
    vector<int> arr = {20, 15, 40, 10, 30};
    h.buildHeap(arr);

    cout << "Heap built from array: ";
    h.printHeap();

    return 0;
}

/*
 Example Run:
 ------------
 Heap after insertions: 2 5 30 10 8
 Min element: 2
 Extracted Min: 2
 Heap after extraction: 5 8 30 10
 Heap built from array: 10 15 40 20 30

 Switching to Max-Heap:
 ----------------------
 - Change comparison signs in heapifyUp() and heapifyDown().
   (Replace '<' with '>' and vice versa)
 - Root will always contain the maximum element instead of minimum.
*/
