#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to add two numbers represented as linked lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result = NULL;
    struct ListNode *current = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        sum %= 10;

        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = sum;
        newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
            current = result;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }

    return result;
}

// Function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to print a linked list
void printList(struct ListNode *node) {
    while (node != NULL) {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    int x, y;

    // Input for first linked list
    printf("Enter the number of elements for the first linked list: ");
    scanf("%d", &x);
    struct ListNode *l1 = NULL;
    printf("Enter the elements for the first linked list in reverse order:\n");
    for (int i = 0; i < x; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode *node = newNode(val);
        node->next = l1;
        l1 = node;
    }

    // Input for second linked list
    printf("Enter the number of elements for the second linked list: ");
    scanf("%d", &y);
    struct ListNode *l2 = NULL;
    printf("Enter the elements for the second linked list in reverse order:\n");
    for (int i = 0; i < y; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode *node = newNode(val);
        node->next = l2;
        l2 = node;
    }

    // Add the two numbers represented by l1 and l2
    struct ListNode *sumList = addTwoNumbers(l1, l2);

    // Print the resulting sum
    printf("Resulting sum of the two numbers:\n");
    printList(sumList);

    // Free allocated memory for linked lists
    while (l1 != NULL) {
        struct ListNode *temp = l1;
        l1 = l1->next;
        free(temp);
    }
    while (l2 != NULL) {
        struct ListNode *temp = l2;
        l2 = l2->next;
        free(temp);
    }
    while (sumList != NULL) {
        struct ListNode *temp = sumList;
        sumList = sumList->next;
        free(temp);
    }

    return 0;
}
