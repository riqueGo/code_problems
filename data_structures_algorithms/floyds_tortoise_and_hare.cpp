/*
* Purpose:
* --------
* - Detect if there is a cycle in a linked list or in a sequence of values.
* - Uses two pointers:
*     * slow (tortoise) moves one step at a time.
*     * fast (hare) moves two steps at a time.
* 
* How it works:
* -------------
* 1. Initialize slow = head, fast = head.
* 2. Move slow by 1 step, fast by 2 steps in each iteration.
* 3. If fast or fast->next becomes NULL → no cycle (end reached).
* 4. If slow == fast at some point → cycle exists.
* 5. To find the starting point of the cycle:
*     - Reset slow to head.
*     - Move slow and fast one step at a time; the node where they meet is the cycle start.
* 
* Complexity:
* -----------
* - Time: O(n) (worst case, traversing the list twice).
* - Space: O(1) (no extra data structure).
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Floyd’s Cycle Detection: returns true if cycle exists
bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;           // move 1 step
        fast = fast->next->next;     // move 2 steps

        if (slow == fast) return true; // cycle detected
    }
    return false; // no cycle
}

// Find the node where cycle begins (if exists), else return nullptr
ListNode* detectCycleStart(ListNode* head) {
    if (!head || !head->next) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    // First, detect if cycle exists
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (!fast || !fast->next) return nullptr; // no cycle

    // Reset slow to head, keep fast at meeting point
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // start of the cycle
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (cycle starts at node with value 3)
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next; // create cycle at node 3

    cout << boolalpha;
    cout << "Has cycle? " << hasCycle(head) << "\n";

    ListNode* startNode = detectCycleStart(head);
    if (startNode)
        cout << "Cycle starts at node with value: " << startNode->val << "\n";
    else
        cout << "No cycle detected.\n";

    return 0;
}

/*
 Output:
 -------
 Has cycle? true
 Cycle starts at node with value: 3
*/