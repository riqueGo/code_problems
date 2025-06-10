package linked_list_cycle;
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null) return false;
        ListNode slow = head, fast = head.next;

        while(fast != null) {
            if(slow == fast) return true;
            slow = slow.next;
            fast = fast.next;
            if(fast == null) return false;
            fast = fast.next;
        }
        return false;
    }
}