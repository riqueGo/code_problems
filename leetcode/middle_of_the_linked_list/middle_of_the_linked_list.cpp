/*
 * Time Complexity: O(N)
 *   - N is the number of nodes in the linked list.
 *   - Each node is visited at most once.
 *
 * Space Complexity: O(1)
 *   - Only a constant amount of extra space is used.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head->next;
        while(fast != nullptr) {
            head = head->next;
            fast = fast->next;
            if(fast == nullptr) return head;
            fast = fast->next;
        }
        return head;
    }
};