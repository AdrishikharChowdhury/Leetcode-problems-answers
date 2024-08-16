/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;
        ListNode next = null;
        
        while (current != null) {
            next = current.next;  // Store next node
            current.next = prev;  // Reverse the link
            prev = current;       // Move prev one step ahead
            current = next;       // Move current one step ahead
        }
        
        return prev;  // New head of the reversed list
    }
}
