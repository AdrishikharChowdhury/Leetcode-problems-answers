class Solution {
    public int appendCharacters(String s, String t) {
        int sPointer = 0;
        int tPointer = 0;
        
        while (sPointer < s.length() && tPointer < t.length()) {
            if (s.charAt(sPointer) == t.charAt(tPointer)) {
                tPointer++;
            }
            sPointer++;
        }
        
        return t.length() - tPointer;
    }
}