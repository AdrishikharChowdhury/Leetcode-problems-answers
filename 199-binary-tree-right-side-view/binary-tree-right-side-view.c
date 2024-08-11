/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int level, int* result, int* resultSize) {
    if (root == NULL) return;
    
    if (level == *resultSize) {
        result[(*resultSize)++] = root->val;
    }
    
    dfs(root->right, level + 1, result, resultSize);
    dfs(root->left, level + 1, result, resultSize);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);  // Assuming max depth is 100
    *returnSize = 0;
    
    dfs(root, 0, result, returnSize);
    
    return result;
}