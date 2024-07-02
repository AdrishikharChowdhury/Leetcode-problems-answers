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
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false; // No cycle if the list is empty or has only one node
        }
        
        ListNode slow = head;
        ListNode fast = head;
        
        while (fast != null && fast.next != null) {
            slow = slow.next; // Move one step at a time
            fast = fast.next.next; // Move two steps at a time
            
            if (slow == fast) {
                return true; // If they meet, there's a cycle
            }
        }
        
        return false;
    }
}
