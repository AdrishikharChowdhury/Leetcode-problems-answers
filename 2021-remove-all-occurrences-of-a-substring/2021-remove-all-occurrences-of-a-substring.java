class Solution {
    public String removeOccurrences(String s, String part) {
        while (s.contains(part)) {
            s = s.replaceFirst(part, ""); // Removes the first occurrence of 'part'
        }
        return s;
    }
}