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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSubPath(ListNode head, TreeNode root) {
        if (head == null) return true;
        if (root == null) return false;
        
        // Check if we can find the linked list starting from this node
        if (dfsCheck(head, root)) return true;
        
        // If not, check in the left and right subtrees
        return isSubPath(head, root.left) || isSubPath(head, root.right);
    }
    
    private boolean dfsCheck(ListNode head, TreeNode root) {
        if (head == null) return true;
        if (root == null) return false;
        
        if (head.val != root.val) return false;
        
        // Continue checking the next nodes in both linked list and tree
        return dfsCheck(head.next, root.left) || dfsCheck(head.next, root.right);
    }
}