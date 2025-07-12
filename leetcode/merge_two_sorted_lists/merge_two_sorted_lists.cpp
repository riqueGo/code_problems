/*
 * Time Complexity: O(N + M)
 *   - N and M are the lengths of the two lists.
 *
 * Space Complexity: O(1)
 *   - If done iteratively, only pointers are used.
 */

#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* curr = &dummy;

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        if(list1 != nullptr) {
            curr->next = list1;
        }

        if(list2 != nullptr) {
            curr->next = list2;
        }

        return dummy.next;
    }
};


int main() {
    ListNode list1(1, new ListNode(2, new ListNode(4)));
    ListNode list2(1, new ListNode(3, new ListNode(4)));

    Solution s;
    ListNode* list = s.mergeTwoLists(&list1, &list2);
    while(list != nullptr) {
        std::cout << list->val << " ";
        list = list->next;
    }
}