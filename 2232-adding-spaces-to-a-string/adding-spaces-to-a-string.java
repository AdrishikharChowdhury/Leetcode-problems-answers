class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder result = new StringBuilder();
        int lastIndex = 0;
        
        for (int space : spaces) {
            // Append characters before the space
            result.append(s.substring(lastIndex, space));
            result.append(" ");
            lastIndex = space;
        }
        
        // Append remaining characters
        result.append(s.substring(lastIndex));
        
        return result.toString();
    }
}