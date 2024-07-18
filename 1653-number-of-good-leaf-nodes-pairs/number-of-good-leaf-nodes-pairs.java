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
    int count = 0;

    public int countPairs(TreeNode root, int distance) {
        dfs(root, distance);
        return count;
    }

    private List<Integer> dfs(TreeNode node, int distance) {
        if (node == null) {
            return new ArrayList<>();
        }

        if (node.left == null && node.right == null) {
            List<Integer> list = new ArrayList<>();
            list.add(0);
            return list;
        }

        List<Integer> leftDistances = dfs(node.left, distance);
        List<Integer> rightDistances = dfs(node.right, distance);

        for (int left : leftDistances) {
            for (int right : rightDistances) {
                if (left + right + 2 <= distance) {
                    count++;
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int left : leftDistances) {
            if (left + 1 < distance) {
                result.add(left + 1);
            }
        }
        for (int right : rightDistances) {
            if (right + 1 < distance) {
                result.add(right + 1);
            }
        }

        return result;
    }
}