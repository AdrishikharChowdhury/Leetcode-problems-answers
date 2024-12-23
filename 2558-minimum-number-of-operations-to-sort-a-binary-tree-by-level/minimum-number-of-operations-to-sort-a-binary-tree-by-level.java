class Solution {
    public int minimumOperations(TreeNode root) {
        if (root == null) return 0;
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int totalOperations = 0;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> level = new ArrayList<>();
            
            // Get all nodes at current level
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                level.add(node.val);
                
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
            
            // Count swaps needed to sort this level
            totalOperations += countMinSwaps(level);
        }
        
        return totalOperations;
    }
    
    private int countMinSwaps(List<Integer> arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        
        // Create array of pairs for tracking original indices
        int[][] pairs = new int[n][2];
        for (int i = 0; i < n; i++) {
            pairs[i][0] = arr.get(i);  // value
            pairs[i][1] = i;           // original position
        }
        
        // Sort based on values
        Arrays.sort(pairs, (a, b) -> a[0] - b[0]);
        
        // Create visited array and initialize all positions as not visited
        boolean[] visited = new boolean[n];
        int swaps = 0;
        
        // Traverse array elements
        for (int i = 0; i < n; i++) {
            // Skip if element is visited or already in correct position
            if (visited[i] || pairs[i][1] == i)
                continue;
                
            // Find cycle size
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = pairs[j][1];
                cycleSize++;
            }
            
            // Add required number of swaps (cycleSize - 1)
            swaps += (cycleSize - 1);
        }
        
        return swaps;
    }
}