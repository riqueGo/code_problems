/*
 * Time Complexity:
 *   - addNum: O(log N)
 *     - Insertion into a heap takes O(log N), and we maintain balance with at most one extra move.
 *   - findMedian: O(1)
 *     - Simply returns the top of one or both heaps.
 *
 * Space Complexity: O(N)
 *   - Both heaps together store all inserted elements (N elements total).
 */

#include <queue>
#include <vector>
#include <algorithm>

using std::priority_queue;
using std::vector;
using std::greater;

class MedianFinder {
public:
    priority_queue<int> smallMaxHeap; // Max heap
    priority_queue<int, vector<int>, greater<int>> largeMinHeap; // Min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(smallMaxHeap.empty() || num <= smallMaxHeap.top()) {
            smallMaxHeap.push(num);
        } else {
            largeMinHeap.push(num);
        }

        if(smallMaxHeap.size() > largeMinHeap.size() + 1) {
            largeMinHeap.push(smallMaxHeap.top());
            smallMaxHeap.pop();
        } else if (largeMinHeap.size() > smallMaxHeap.size()) {
            smallMaxHeap.push(largeMinHeap.top());
            largeMinHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallMaxHeap.size() > largeMinHeap.size()) {
            return smallMaxHeap.top();
        }
        return (smallMaxHeap.top() + largeMinHeap.top()) / 2.0;
    }
};