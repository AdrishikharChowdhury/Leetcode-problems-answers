class Solution {
    public int minChanges(int n, int k) {
        int changes = 0;
        
        while (n > 0 || k > 0) {
            int bitN = n & 1;
            int bitK = k & 1;
            
            if (bitN == 1 && bitK == 0) {
                changes++;
            } else if (bitN == 0 && bitK == 1) {
                return -1;
            }
            
            n >>= 1;
            k >>= 1;
        }
        
        return changes;
    }
}