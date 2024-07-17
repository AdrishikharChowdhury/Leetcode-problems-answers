/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* deleteNodes(struct TreeNode* node, bool* to_delete_set, struct TreeNode** forest, int* returnSize);

struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize) {
    bool* to_delete_set = calloc(1001, sizeof(bool)); // Assuming values are in range 1-1000
    for (int i = 0; i < to_deleteSize; i++) {
        to_delete_set[to_delete[i]] = true;
    }
    
    struct TreeNode** forest = malloc(1001 * sizeof(struct TreeNode*));
    *returnSize = 0;
    
    root = deleteNodes(root, to_delete_set, forest, returnSize);
    
    if (root != NULL) {
        forest[(*returnSize)++] = root;
    }
    
    free(to_delete_set);
    return forest;
}

struct TreeNode* deleteNodes(struct TreeNode* node, bool* to_delete_set, struct TreeNode** forest, int* returnSize) {
    if (node == NULL) return NULL;
    
    bool should_delete = to_delete_set[node->val];
    
    node->left = deleteNodes(node->left, to_delete_set, forest, returnSize);
    node->right = deleteNodes(node->right, to_delete_set, forest, returnSize);
    
    if (should_delete) {
        if (node->left != NULL) {
            forest[(*returnSize)++] = node->left;
        }
        if (node->right != NULL) {
            forest[(*returnSize)++] = node->right;
        }
        return NULL;
    }
    
    return node;
}