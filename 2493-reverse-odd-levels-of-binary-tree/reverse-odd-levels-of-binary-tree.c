struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    if (!root) return NULL;
    
    // For perfect binary tree, maximum nodes at any level is 2^h
    // We'll allocate enough space for maximum possible nodes at deepest level
    int maxQueueSize = 20000;  // Safe size for given constraints
    struct TreeNode** queue = (struct TreeNode**)malloc(maxQueueSize * sizeof(struct TreeNode*));
    if (!queue) return root;  // Handle allocation failure
    
    int front = 0, rear = 0;
    int level = 0;
    
    queue[rear++] = root;
    
    while (front < rear && queue[front]->left != NULL) {  // Check if next level exists
        int levelSize = rear - front;
        
        // Store current level nodes
        int* values = NULL;
        if (level % 2 == 0) {  // If next level will be odd
            values = (int*)malloc(levelSize * 2 * sizeof(int));
            if (!values) {
                free(queue);
                return root;
            }
            int idx = 0;
            
            // Store values of next (odd) level
            for (int i = front; i < rear; i++) {
                values[idx++] = queue[i]->left->val;
                values[idx++] = queue[i]->right->val;
            }
            
            // Reverse the values
            for (int i = 0; i < idx/2; i++) {
                int temp = values[i];
                values[i] = values[idx-1-i];
                values[idx-1-i] = temp;
            }
            
            // Apply reversed values
            idx = 0;
            for (int i = front; i < rear; i++) {
                queue[i]->left->val = values[idx++];
                queue[i]->right->val = values[idx++];
            }
            
            free(values);
        }
        
        // Add next level to queue
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = queue[front++];
            if (curr->left) {
                queue[rear++] = curr->left;
                queue[rear++] = curr->right;
            }
        }
        
        level++;
    }
    
    free(queue);
    return root;
}