#include <iostream>
#include<vector>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        ListNode* minBaseNode = new ListNode(501);
        int minNodeVal;
        int minNodeIndex = -1;

        while(curr != nullptr) {
            minNodeVal = 501;
            for(int i = 0; i < lists.size(); ++i) {
                ListNode* node = lists[i];
                if(node == nullptr) continue;

                if(node->val < minNodeVal) {
                    minNodeVal = node->val;
                    minNodeIndex = i;
                }
            }
            if(minNodeVal == 501) break;

            curr->next = lists[minNodeIndex];
            curr = curr->next;
            lists[minNodeIndex] = lists[minNodeIndex]->next;
        }
        return head->next;
    }
};

int main() {
    // Example usage
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));
    
    vector<ListNode*> lists = {l1, l2, l3};
    
    Solution solution;
    ListNode* mergedList = solution.mergeKLists(lists);
    
    // Print merged list
    while (mergedList != nullptr) {
        std::cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    
    return 0;
}