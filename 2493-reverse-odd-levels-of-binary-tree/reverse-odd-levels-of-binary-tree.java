class Solution {
    public TreeNode reverseOddLevels(TreeNode root) {
        if (root == null) return null;
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        boolean isOddLevel = false;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            List<TreeNode> levelNodes = new ArrayList<>();
            
            // Get all nodes at current level
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                if (node.left != null) {
                    queue.offer(node.left);
                    queue.offer(node.right);
                }
                if (isOddLevel) {
                    levelNodes.add(node);
                }
            }
            
            // Reverse values at odd levels
            if (isOddLevel) {
                int left = 0, right = levelNodes.size() - 1;
                while (left < right) {
                    int temp = levelNodes.get(left).val;
                    levelNodes.get(left).val = levelNodes.get(right).val;
                    levelNodes.get(right).val = temp;
                    left++;
                    right--;
                }
            }
            
            isOddLevel = !isOddLevel;
        }
        
        return root;
    }
}