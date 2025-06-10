/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode* reverseList(ListNode* head) {
        ListNode *p, *tmp;
        while(head != nullptr) {
            tmp = head->next;
            head->next = p;
            p = head;
            head = tmp;
        }
        return p;
    }
};

int main() {
    ListNode list(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution s;
    s.reverseList(&list);
}