/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    
    // Allocate space for maximum possible levels
    int* result = (int*)malloc(10000 * sizeof(int));
    *returnSize = 0;
    
    // Create queue for BFS
    struct TreeNode** queue = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    
    // Add root to queue
    queue[rear++] = root;
    
    while (front < rear) {
        int levelSize = rear - front;
        int maxValue = INT_MIN;
        
        // Process current level
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            maxValue = fmax(maxValue, node->val);
            
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        
        result[(*returnSize)++] = maxValue;
    }
    
    // Free queue and resize result
    free(queue);
    result = realloc(result, (*returnSize) * sizeof(int));
    return result;
}