/*
 * Time Complexity: O(L)
 *   - L is the length of the linked list.
 *
 * Space Complexity: O(1)
 *   - Only a constant amount of extra space is used (dummy node and pointers).
 */

#include <queue>

using std::queue;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        for(int i = 0; i < n; i++) {
            curr = curr->next;
        }

        while(curr != nullptr) {
            prev = prev->next;
            curr = curr->next;
        }

        ListNode* todel = prev->next;
        prev->next = todel->next;
        delete todel;
        return dummy->next;
    }
};

int main() {
    ListNode* head = new ListNode(1, new ListNode(2));
    int n = 2;
    Solution sol;
    head = sol.removeNthFromEnd(head, n);
}