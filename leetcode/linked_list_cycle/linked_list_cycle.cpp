/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *slow = head, *fast = head->next;

        while(fast != nullptr) {
            if(slow == fast) return true;
            slow = slow->next;
            fast = fast->next;
            if(fast == nullptr) return false;
            fast = fast->next;
        }
        return false;
    }
};