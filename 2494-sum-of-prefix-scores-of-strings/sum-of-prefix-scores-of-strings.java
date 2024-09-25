class Solution {
    class TrieNode {
        TrieNode[] children;
        int count;
        
        TrieNode() {
            children = new TrieNode[26];
            count = 0;
        }
    }
    
    public int[] sumPrefixScores(String[] words) {
        TrieNode root = new TrieNode();
        
        // Build the Trie
        for (String word : words) {
            insertWord(root, word);
        }
        
        int[] answer = new int[words.length];
        
        // Calculate scores for each word
        for (int i = 0; i < words.length; i++) {
            answer[i] = calculateScore(root, words[i]);
        }
        
        return answer;
    }
    
    private void insertWord(TrieNode node, String word) {
        for (char c : word.toCharArray()) {
            int index = c - 'a';
            if (node.children[index] == null) {
                node.children[index] = new TrieNode();
            }
            node = node.children[index];
            node.count++;
        }
    }
    
    private int calculateScore(TrieNode node, String word) {
        int score = 0;
        for (char c : word.toCharArray()) {
            int index = c - 'a';
            if (node.children[index] == null) {
                break;
            }
            node = node.children[index];
            score += node.count;
        }
        return score;
    }
}