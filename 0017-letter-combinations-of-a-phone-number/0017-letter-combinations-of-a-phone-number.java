class Solution {
    // Map digits to letters
    private final String[] letterMap = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
    
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if (digits == null || digits.length() == 0) {
            return result;
        }
        
        backtrack(digits, 0, new StringBuilder(), result);
        return result;
    }
    
    private void backtrack(String digits, int index, StringBuilder current, List<String> result) {
        // Base case: if we've processed all digits
        if (index == digits.length()) {
            result.add(current.toString());
            return;
        }
        
        // Get current digit and its corresponding letters
        String letters = letterMap[digits.charAt(index) - '0'];
        
        // Try each letter for current digit
        for (char letter : letters.toCharArray()) {
            current.append(letter);
            backtrack(digits, index + 1, current, result);
            current.setLength(current.length() - 1); // backtrack
        }
    }
}