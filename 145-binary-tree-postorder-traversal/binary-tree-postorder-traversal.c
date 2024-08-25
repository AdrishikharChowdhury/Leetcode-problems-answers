/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void postorder(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;
    
    postorder(root->left, result, returnSize);
    postorder(root->right, result, returnSize);
    result[(*returnSize)++] = root->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(10000 * sizeof(int));  // Assuming max 10000 nodes
    *returnSize = 0;
    
    postorder(root, result, returnSize);
    
    return result;
}