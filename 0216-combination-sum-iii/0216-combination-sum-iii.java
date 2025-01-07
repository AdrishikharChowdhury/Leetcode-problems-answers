class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(k, n, 1, new ArrayList<>(), result);
        return result;
    }
    
    private void backtrack(int k, int remainSum, int start, 
                          List<Integer> current, 
                          List<List<Integer>> result) {
        // Base cases
        if (remainSum < 0 || current.size() > k) return;
        
        if (current.size() == k) {
            if (remainSum == 0) {
                result.add(new ArrayList<>(current));
            }
            return;
        }
        
        // Try each possible number
        for (int i = start; i <= 9; i++) {
            current.add(i);
            backtrack(k, remainSum - i, i + 1, current, result);
            current.remove(current.size() - 1);  // backtrack
        }
    }
}