class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        // Split sentences into words
        String[] words1 = sentence1.split(" ");
        String[] words2 = sentence2.split(" ");
        
        // Ensure words1 is the shorter array
        if (words1.length > words2.length) {
            String[] temp = words1;
            words1 = words2;
            words2 = temp;
        }
        
        int n1 = words1.length;
        int n2 = words2.length;
        
        int left = 0;
        // Match words from left
        while (left < n1 && words1[left].equals(words2[left])) {
            left++;
        }
        
        int right = 0;
        // Match words from right
        while (right < n1 - left && 
               words1[n1 - 1 - right].equals(words2[n2 - 1 - right])) {
            right++;
        }
        
        return (left + right) >= n1;
    }
    
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        // Test cases
        System.out.println("Test 1: " + 
            solution.areSentencesSimilar(
                "My name is Haley", 
                "My Haley")); // Should print true
        
        System.out.println("Test 2: " + 
            solution.areSentencesSimilar(
                "of", 
                "A lot of words")); // Should print true
        
        System.out.println("Test 3: " + 
            solution.areSentencesSimilar(
                "Eating right now", 
                "Eating")); // Should print true
                
        System.out.println("Test 4: " + 
            solution.areSentencesSimilar(
                "A B C", 
                "A D B C")); // Should print true
    }
}