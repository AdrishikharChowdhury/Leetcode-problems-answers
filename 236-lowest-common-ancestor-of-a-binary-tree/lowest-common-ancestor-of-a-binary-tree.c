/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // Base case: if root is null or equal to either p or q
    if (root == NULL || root == p || root == q) {
        return root;
    }
    
    // Recursively search in left and right subtrees
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    // If both left and right are non-null, root is the LCA
    if (left != NULL && right != NULL) {
        return root;
    }
    
    // If one of them is null, return the non-null one
    return (left != NULL) ? left : right;
}