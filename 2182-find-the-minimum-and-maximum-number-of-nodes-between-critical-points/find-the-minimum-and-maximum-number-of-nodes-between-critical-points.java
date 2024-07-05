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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] result = new int[]{-1, -1};
        
        if (head == null || head.next == null || head.next.next == null) {
            return result;
        }
        
        ListNode prev = head;
        ListNode curr = head.next;
        ListNode next = curr.next;
        
        int firstCritical = -1;
        int lastCritical = -1;
        int prevCritical = -1;
        int minDist = Integer.MAX_VALUE;
        int index = 1;
        
        while (next != null) {
            if ((curr.val > prev.val && curr.val > next.val) ||
                (curr.val < prev.val && curr.val < next.val)) {
                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    if (prevCritical != -1) {
                        minDist = Math.min(index - prevCritical, minDist);
                    }
                }
                lastCritical = index;
                prevCritical = index;
            }
            prev = curr;
            curr = next;
            next = next.next;
            index++;
        }
        
        if (lastCritical - firstCritical > 0) {
            result[0] = minDist;
            result[1] = lastCritical - firstCritical;
        }
        
        return result;
    }
}