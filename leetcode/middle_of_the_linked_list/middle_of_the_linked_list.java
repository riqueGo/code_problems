package middle_of_the_linked_list;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode fast = head.next;
        while(fast!=null) {
            head = head.next;
            fast = fast.next;
            if(fast == null) return head;
            fast = fast.next;
        }
        return head;
    }
}
