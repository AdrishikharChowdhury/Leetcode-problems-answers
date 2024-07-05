/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
	if (root == NULL) return NULL;
    
    struct Node* current = root;
    struct Node* prev = NULL;
    struct Node* leftmost = NULL;
    
    while (current != NULL) {
        while (current != NULL) {
            if (current->left != NULL) {
                if (prev != NULL) {
                    prev->next = current->left;
                } else {
                    leftmost = current->left;
                }
                prev = current->left;
            }
            
            if (current->right != NULL) {
                if (prev != NULL) {
                    prev->next = current->right;
                } else {
                    leftmost = current->right;
                }
                prev = current->right;
            }
            
            current = current->next;
        }
        
        current = leftmost;
        prev = NULL;
        leftmost = NULL;
    }
    
    return root;
}