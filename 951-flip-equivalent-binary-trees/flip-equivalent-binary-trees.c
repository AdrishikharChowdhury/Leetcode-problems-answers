
bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2) {
    // If both nodes are NULL, they are equivalent
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    
    // If one node is NULL and other isn't, they are not equivalent
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    
    // If values are different, they are not equivalent
    if (root1->val != root2->val) {
        return false;
    }
    
    // Check both possible arrangements:
    // 1. Without flip: left with left, right with right
    // 2. With flip: left with right, right with left
    return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
           (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
}