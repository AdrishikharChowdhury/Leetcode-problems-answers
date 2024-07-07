class Solution {
    public String mergeAlternately(String word1, String word2) {
        int len1=word1.length();
        int len2=word2.length();
        int mlen=len1+len2;
        StringBuilder merge = new StringBuilder(mlen);       
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            merge.append(word1.charAt(i++));
            merge.append(word2.charAt(j++));
        }
        
        while (i < len1) {
            merge.append(word1.charAt(i++));
        }
        
        while (j < len2) {
            merge.append(word2.charAt(j++));
        }
        
        return merge.toString();
    }
}