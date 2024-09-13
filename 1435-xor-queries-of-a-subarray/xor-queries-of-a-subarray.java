class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int[] prefixXOR = new int[n + 1];
        
        // Calculate prefix XOR array
        for (int i = 0; i < n; i++) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }
        
        int m = queries.length;
        int[] answer = new int[m];
        
        // Process queries
        for (int i = 0; i < m; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            answer[i] = prefixXOR[right + 1] ^ prefixXOR[left];
        }
        
        return answer;
    }
}