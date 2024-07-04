struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to merge nodes
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    current->next = NULL;

    struct ListNode* temp = head;
    int sum = 0;

    while (temp != NULL) {
        if (temp->val == 0) {
            if (sum != 0) {
                current->next = createNode(sum);
                current = current->next;
                sum = 0;
            }
        } else {
            sum += temp->val;
        }
        temp = temp->next;
    }

    return dummy.next;
}