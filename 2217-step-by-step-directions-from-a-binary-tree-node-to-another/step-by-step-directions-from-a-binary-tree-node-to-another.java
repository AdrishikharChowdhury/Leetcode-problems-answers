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
    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder path1 = new StringBuilder();
        StringBuilder path2 = new StringBuilder();
        
        // Find paths from root to start and destination
        findPath(root, startValue, path1);
        findPath(root, destValue, path2);
        
        // Find the common prefix
        int i = 0;
        while (i < path1.length() && i < path2.length() && path1.charAt(i) == path2.charAt(i)) {
            i++;
        }
        
        // Construct the result
        StringBuilder result = new StringBuilder();
        for (int j = i; j < path1.length(); j++) {
            result.append('U');
        }
        result.append(path2.substring(i));
        
        return result.toString();
    }
    
    private boolean findPath(TreeNode node, int value, StringBuilder path) {
        if (node == null) {
            return false;
        }
        
        if (node.val == value) {
            return true;
        }
        
        if (findPath(node.left, value, path)) {
            path.insert(0, 'L');
            return true;
        }
        
        if (findPath(node.right, value, path)) {
            path.insert(0, 'R');
            return true;
        }
        
        return false;
    }
}