/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
    int** matrix = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    *returnSize = m;
    
    // Initialize the direction and indices
    int direction = 0; // 0: right, 1: down, 2: left, 3: up
    int rowStart = 0, rowEnd = m - 1, colStart = 0, colEnd = n - 1;
    
    struct ListNode* current = head;
    
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            matrix[i][j] = -1;
        }
    }
    
    while (rowStart <= rowEnd && colStart <= colEnd) {
        if (direction == 0) { // Right
            for (int col = colStart; col <= colEnd; col++) {
                matrix[rowStart][col] = (current != NULL) ? current->val : -1;
                if (current != NULL) current = current->next;
            }
            rowStart++;
        } else if (direction == 1) { // Down
            for (int row = rowStart; row <= rowEnd; row++) {
                matrix[row][colEnd] = (current != NULL) ? current->val : -1;
                if (current != NULL) current = current->next;
            }
            colEnd--;
        } else if (direction == 2) { // Left
            for (int col = colEnd; col >= colStart; col--) {
                matrix[rowEnd][col] = (current != NULL) ? current->val : -1;
                if (current != NULL) current = current->next;
            }
            rowEnd--;
        } else { // Up
            for (int row = rowEnd; row >= rowStart; row--) {
                matrix[row][colStart] = (current != NULL) ? current->val : -1;
                if (current != NULL) current = current->next;
            }
            colStart++;
        }
        
        direction = (direction + 1) % 4;
    }
    
    return matrix;
}