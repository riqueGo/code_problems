package find_median_from_data_stream;

import java.util.Collections;
import java.util.PriorityQueue;

class MedianFinder {
    private PriorityQueue<Integer> smallMaxHeap; // Max Heap (left side)
    private PriorityQueue<Integer> largeMinHeap; // Min Heap (right side)

    public MedianFinder() {
        smallMaxHeap = new PriorityQueue<>(Collections.reverseOrder()); // Max heap
        largeMinHeap = new PriorityQueue<>(); // Min heap
    }

    public void addNum(int num) {
        if (smallMaxHeap.isEmpty() || num <= smallMaxHeap.peek()) {
            smallMaxHeap.offer(num);
        } else {
            largeMinHeap.offer(num);
        }

        // Balance the heaps
        if (smallMaxHeap.size() > largeMinHeap.size() + 1) {
            largeMinHeap.offer(smallMaxHeap.poll());
        } else if (largeMinHeap.size() > smallMaxHeap.size()) {
            smallMaxHeap.offer(largeMinHeap.poll());
        }
    }

    public double findMedian() {
        if (smallMaxHeap.size() > largeMinHeap.size()) {
            return smallMaxHeap.peek();
        }
        return (smallMaxHeap.peek() + largeMinHeap.peek()) / 2.0;
    }
}
