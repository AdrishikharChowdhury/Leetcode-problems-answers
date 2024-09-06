public class Solution {
    
    public static ListNode modifiedList(int[] nums, ListNode head) {
        // Create a hash set to store nums values
        HashSet<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
        }
        
        // Create a dummy node to simplify list modification
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode current = dummy;
        
        // Traverse the linked list
        while (current.next != null) {
            if (numSet.contains(current.next.val)) {
                // Remove the node
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        
        return dummy.next;
    }
}
