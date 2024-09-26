#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int start;
    int end;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
} MyCalendar;

Node* createNode(int start, int end) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->start = start;
    newNode->end = end;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool canBook(Node* root, int start, int end) {
    if (root == NULL) {
        return true;
    }
    
    if (start < root->end && end > root->start) {
        return false;
    }
    
    if (start < root->start) {
        return canBook(root->left, start, end);
    } else {
        return canBook(root->right, start, end);
    }
}

Node* insert(Node* root, int start, int end) {
    if (root == NULL) {
        return createNode(start, end);
    }
    
    if (start < root->start) {
        root->left = insert(root->left, start, end);
    } else {
        root->right = insert(root->right, start, end);
    }
    
    return root;
}

MyCalendar* myCalendarCreate() {
    MyCalendar* obj = (MyCalendar*)malloc(sizeof(MyCalendar));
    obj->root = NULL;
    return obj;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    if (canBook(obj->root, start, end)) {
        obj->root = insert(obj->root, start, end);
        return true;
    }
    return false;
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void myCalendarFree(MyCalendar* obj) {
    freeTree(obj->root);
    free(obj);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 * myCalendarFree(obj);
 */