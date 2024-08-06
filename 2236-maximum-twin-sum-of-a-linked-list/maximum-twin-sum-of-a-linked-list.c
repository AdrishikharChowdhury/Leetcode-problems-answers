/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* nextTemp = current->next;
        current->next = prev;
        prev = current;
        current = nextTemp;
    }
    return prev;
}

int pairSum(struct ListNode* head) {
    // Find the middle of the list
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse the second half of the list
    struct ListNode* secondHalf = reverseList(slow->next);
    slow->next = NULL;
    
    // Calculate the maximum twin sum
    int maxTwinSum = 0;
    struct ListNode* first = head;
    struct ListNode* second = secondHalf;
    while (first != NULL && second != NULL) {
        int twinSum = first->val + second->val;
        if (twinSum > maxTwinSum) {
            maxTwinSum = twinSum;
        }
        first = first->next;
        second = second->next;
    }
    
    return maxTwinSum;
}