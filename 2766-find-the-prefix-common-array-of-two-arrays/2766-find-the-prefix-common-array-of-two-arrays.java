class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] C = new int[n];
        boolean[] seenA = new boolean[n + 1];
        boolean[] seenB = new boolean[n + 1];
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            // Mark current numbers as seen
            seenA[A[i]] = true;
            seenB[B[i]] = true;
            
            // If both arrays have seen the current numbers, increment count
            if (seenA[A[i]] && seenB[A[i]]) count++;
            if (A[i] != B[i] && seenA[B[i]] && seenB[B[i]]) count++;
            
            C[i] = count;
        }
        
        return C;
    }
}