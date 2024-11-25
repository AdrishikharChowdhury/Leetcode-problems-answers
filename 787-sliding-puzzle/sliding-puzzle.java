class Solution {
    public int slidingPuzzle(int[][] board) {
        // Convert board to string for easier comparison
        String target = "123450";
        String start = "";
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++) {
                start += board[i][j];
            }
        }
        
        // Possible moves for each position
        int[][] moves = {
            {1, 3},      // position 0
            {0, 2, 4},   // position 1
            {1, 5},      // position 2
            {0, 4},      // position 3
            {1, 3, 5},   // position 4
            {2, 4}       // position 5
        };
        
        // BFS
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.offer(start);
        visited.add(start);
        int steps = 0;
        
        while(!queue.isEmpty()) {
            int size = queue.size();
            
            for(int i = 0; i < size; i++) {
                String current = queue.poll();
                if(current.equals(target)) {
                    return steps;
                }
                
                int zero = current.indexOf('0');
                // Try all possible moves
                for(int move : moves[zero]) {
                    String next = swap(current, zero, move);
                    if(!visited.contains(next)) {
                        visited.add(next);
                        queue.offer(next);
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
    
    private String swap(String str, int i, int j) {
        char[] chars = str.toCharArray();
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
        return new String(chars);
    }
}