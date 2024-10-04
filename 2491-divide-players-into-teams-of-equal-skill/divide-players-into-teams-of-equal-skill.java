class Solution {
    public long dividePlayers(int[] skill) {
        int n = skill.length;
        // Sort the array
        Arrays.sort(skill);
        
        // First team's total skill will be our target
        int targetSum = skill[0] + skill[n-1];
        long totalChemistry = 0;
        
        // Check each pair from both ends
        for (int i = 0; i < n/2; i++) {
            int currentSum = skill[i] + skill[n-1-i];
            // If any pair doesn't match target sum, return -1
            if (currentSum != targetSum) {
                return -1;
            }
            // Add chemistry of current pair to total
            totalChemistry += (long)skill[i] * skill[n-1-i];
        }
        
        return totalChemistry;
    }
}