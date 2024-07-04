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
    public ListNode mergeNodes(ListNode head) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;

        ListNode temp = head;
        int sum = 0;

        while (temp != null) {
            if (temp.val == 0) {
                if (sum != 0) {
                    current.next = new ListNode(sum);
                    current = current.next;
                    sum = 0;
                }
            } else {
                sum += temp.val;
            }
            temp = temp.next;
        }

        return dummy.next;
    }
}