/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Function to calculate the Greatest Common Divisor using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;  // No changes needed for empty list or single node
    }
    
    struct ListNode* current = head;
    
    while (current->next != NULL) {
        int gcdValue = gcd(current->val, current->next->val);
        
        // Create a new node with the GCD value
        struct ListNode* gcdNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        gcdNode->val = gcdValue;
        
        // Insert the new node between current and current->next
        gcdNode->next = current->next;
        current->next = gcdNode;
        
        // Move to the node after the newly inserted GCD node
        current = gcdNode->next;
    }
    
    return head;
}