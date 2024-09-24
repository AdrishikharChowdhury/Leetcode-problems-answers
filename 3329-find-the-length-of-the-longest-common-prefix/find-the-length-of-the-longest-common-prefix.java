class Solution {
    private static class TrieNode {
        TrieNode[] children;
        boolean isEnd;
        
        TrieNode() {
            children = new TrieNode[10];
            isEnd = false;
        }
    }
    
    private void insert(TrieNode root, String s) {
        TrieNode node = root;
        for (char c : s.toCharArray()) {
            int index = c - '0';
            if (node.children[index] == null) {
                node.children[index] = new TrieNode();
            }
            node = node.children[index];
        }
        node.isEnd = true;
    }
    
    private int findLongestPrefix(TrieNode root, String s) {
        TrieNode node = root;
        for (int i = 0; i < s.length(); i++) {
            int index = s.charAt(i) - '0';
            if (node.children[index] == null) {
                return i;
            }
            node = node.children[index];
        }
        return s.length();
    }
    
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        TrieNode root = new TrieNode();
        
        // Insert all numbers from arr1 into the trie
        for (int num : arr1) {
            insert(root, String.valueOf(num));
        }
        
        int maxLength = 0;
        
        // Find the longest common prefix for each number in arr2
        for (int num : arr2) {
            String s = String.valueOf(num);
            int length = findLongestPrefix(root, s);
            maxLength = Math.max(maxLength, length);
        }
        
        return maxLength;
    }
}