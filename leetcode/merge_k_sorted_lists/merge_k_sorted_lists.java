package merge_k_sorted_lists;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = new ListNode(0); // dummy node
        ListNode curr = head;

        while (true) {
            int minNodeVal = 501;
            int minNodeIndex = -1;

            for (int i = 0; i < lists.length; i++) {
                ListNode node = lists[i];
                if (node == null) continue;

                if (node.val < minNodeVal) {
                    minNodeVal = node.val;
                    minNodeIndex = i;
                }
            }

            if (minNodeIndex == -1) break;

            curr.next = lists[minNodeIndex];
            curr = curr.next;

            lists[minNodeIndex] = lists[minNodeIndex].next;
        }

        return head.next;
    }
}
