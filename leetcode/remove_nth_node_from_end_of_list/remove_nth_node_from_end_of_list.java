package remove_nth_node_from_end_of_list;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) return head;

        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        ListNode curr = head;

        for (int i = 0; i < n; i++) {
            curr = curr.next;
        }

        while (curr != null) {
            prev = prev.next;
            curr = curr.next;
        }

        ListNode toDelete = prev.next;
        prev.next = toDelete.next;

        return dummy.next;
    }
}
