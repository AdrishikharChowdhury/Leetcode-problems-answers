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
    public int goodNodes(TreeNode root) {
        return countGoodNodes(root, Integer.MIN_VALUE);
    }
    
    private int countGoodNodes(TreeNode node, int maxSoFar) {
        if (node == null) {
            return 0;
        }
        
        int count = (node.val >= maxSoFar) ? 1 : 0;
        int newMax = Math.max(maxSoFar, node.val);
        
        count += countGoodNodes(node.left, newMax);
        count += countGoodNodes(node.right, newMax);
        
        return count;
    }
}