/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

void postorderTraversal(struct Node* root, int* result, int* returnSize) {
    if (root == NULL) return;
    
    for (int i = 0; i < root->numChildren; i++) {
        postorderTraversal(root->children[i], result, returnSize);
    }
    
    result[(*returnSize)++] = root->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorder(struct Node* root, int* returnSize) {
    int* result = malloc(10000 * sizeof(int));  // Assuming max 10000 nodes
    *returnSize = 0;
    
    postorderTraversal(root, result, returnSize);
    
    return result;
}