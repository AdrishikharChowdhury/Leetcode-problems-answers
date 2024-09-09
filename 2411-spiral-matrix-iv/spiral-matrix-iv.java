/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] matrix = new int[m][n];
        
        // Initialize the direction and indices
        int direction = 0; // 0: right, 1: down, 2: left, 3: up
        int rowStart = 0, rowEnd = m - 1, colStart = 0, colEnd = n - 1;
        
        ListNode current = head;
        
        while (rowStart <= rowEnd && colStart <= colEnd) {
            if (direction == 0) { // Right
                for (int col = colStart; col <= colEnd; col++) {
                    matrix[rowStart][col] = (current != null) ? current.val : -1;
                    if (current != null) current = current.next;
                }
                rowStart++;
            } else if (direction == 1) { // Down
                for (int row = rowStart; row <= rowEnd; row++) {
                    matrix[row][colEnd] = (current != null) ? current.val : -1;
                    if (current != null) current = current.next;
                }
                colEnd--;
            } else if (direction == 2) { // Left
                for (int col = colEnd; col >= colStart; col--) {
                    matrix[rowEnd][col] = (current != null) ? current.val : -1;
                    if (current != null) current = current.next;
                }
                rowEnd--;
            } else { // Up
                for (int row = rowEnd; row >= rowStart; row--) {
                    matrix[row][colStart] = (current != null) ? current.val : -1;
                    if (current != null) current = current.next;
                }
                colStart++;
            }
            
            direction = (direction + 1) % 4;
        }
        
        return matrix;
    }
}