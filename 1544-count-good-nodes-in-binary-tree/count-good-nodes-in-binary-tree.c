/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countGoodNodes(struct TreeNode* root, int maxSoFar) {
    if (root == NULL) {
        return 0;
    }
    
    int count = (root->val >= maxSoFar) ? 1 : 0;
    int newMax = (root->val > maxSoFar) ? root->val : maxSoFar;
    
    count += countGoodNodes(root->left, newMax);
    count += countGoodNodes(root->right, newMax);
    
    return count;
}

int goodNodes(struct TreeNode* root) {
    return countGoodNodes(root, INT_MIN);
}