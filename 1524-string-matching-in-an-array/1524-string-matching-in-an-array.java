class Solution {
    public List<String> stringMatching(String[] words) {
        Set<String> result = new HashSet<>(); // Use Set to avoid duplicates
        
        // Compare each word with every other word
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words.length; j++) {
                if (i != j && words[i].length() < words[j].length() && 
                    words[j].indexOf(words[i]) != -1) {
                    result.add(words[i]);
                    break; // Found a match, no need to check further
                }
            }
        }
        
        return new ArrayList<>(result);
    }
}