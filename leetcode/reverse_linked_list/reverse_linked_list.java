package reverse_linked_list;

class ListNode {
   int val;
   ListNode next;
   ListNode() {}
   ListNode(int val) { this.val = val; }
   ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null) return head;
        ListNode previous = null, tmp = null;

        while(head != null) {
            tmp = head.next;
            head.next = previous;
            previous = head;
            head = tmp;
        }

        return previous;
    }
}
