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
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Set<Integer> toDelete = new HashSet<>();
        for (int val : to_delete) {
            toDelete.add(val);
        }
        
        List<TreeNode> forest = new ArrayList<>();
        
        root = deleteNodes(root, toDelete, forest);
        
        if (root != null) {
            forest.add(root);
        }
        
        return forest;
    }
    
    private TreeNode deleteNodes(TreeNode node, Set<Integer> toDelete, List<TreeNode> forest) {
        if (node == null) {
            return null;
        }
        
        boolean deleted = toDelete.contains(node.val);
        
        node.left = deleteNodes(node.left, toDelete, forest);
        node.right = deleteNodes(node.right, toDelete, forest);
        
        if (deleted) {
            if (node.left != null) {
                forest.add(node.left);
            }
            if (node.right != null) {
                forest.add(node.right);
            }
            return null;
        }
        
        return node;
    }
}