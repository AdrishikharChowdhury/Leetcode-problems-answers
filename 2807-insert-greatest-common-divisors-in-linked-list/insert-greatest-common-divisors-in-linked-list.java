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
    // Function to calculate the Greatest Common Divisor using Euclidean algorithm
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head == null || head.next == null) {
            return head;  // No changes needed for empty list or single node
        }
        
        ListNode current = head;
        
        while (current.next != null) {
            int gcdValue = gcd(current.val, current.next.val);
            
            // Create a new node with the GCD value
            ListNode gcdNode = new ListNode(gcdValue);
            
            // Insert the new node between current and current.next
            gcdNode.next = current.next;
            current.next = gcdNode;
            
            // Move to the node after the newly inserted GCD node
            current = gcdNode.next;
        }
        
        return head;
    }
}