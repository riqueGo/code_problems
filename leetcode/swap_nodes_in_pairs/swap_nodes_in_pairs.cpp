/*
 * Time Complexity: O(N)
 *   - N is the number of nodes in the linked list.
 *   - Each node is visited and swapped at most once.
 *
 * Space Complexity: O(1)
 *   - Constant extra space used (only a few pointers).
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head != nullptr && head->next != nullptr) {
            ListNode* first = head;
            ListNode* second = head->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
            head = first->next;
        }

        return dummy.next;
    }
};
