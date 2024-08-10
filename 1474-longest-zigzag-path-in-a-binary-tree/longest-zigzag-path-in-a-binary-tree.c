int maxZigZag = 0;

void dfs(struct TreeNode* node, int isRight, int length) {
    if (node == NULL) return;

    maxZigZag = (length > maxZigZag) ? length : maxZigZag;

    if (isRight) {
        // Move right and change direction to left
        dfs(node->right, 0, length + 1);
        // Start a new path from the left child
        dfs(node->left, 1, 1);
    } else {
        // Move left and change direction to right
        dfs(node->left, 1, length + 1);
        // Start a new path from the right child
        dfs(node->right, 0, 1);
    }
}

int longestZigZag(struct TreeNode* root) {
    if (root == NULL) return 0;
    
    maxZigZag = 0;
    dfs(root, 0, 0); // Start with direction 'left'
    dfs(root, 1, 0); // Start with direction 'right'
    return maxZigZag;
}