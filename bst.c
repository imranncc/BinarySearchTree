#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} NODE;

NODE* new_node(int value) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert1(NODE* p, int value) {
    if (value < p->value) {
        if (p->left == NULL) {
            p->left = new_node(value);
        } else {
            insert1(p->left, value);
        }
    } else if (value > p->value) {
        if (p->right == NULL) {
            p->right = new_node(value);
        } else {
            insert1(p->right, value);
        }
    }
}

NODE* insert(NODE* root, int value) {
    if (root == NULL) {
        return new_node(value);
    } else {
        insert1(root, value);
        return root;
    }
}

void InOrder1(NODE* p) {
    if (p == NULL) {
        return;
    }
    InOrder1(p->left);
    printf("%d ", p->value);
    InOrder1(p->right);
}

void InOrder(NODE* root) {
    if (root == NULL) {
        printf("empty tree\n");
    } else {
        InOrder1(root);
    }
    printf("\n");
}

int main() {
    NODE* root = NULL;
    char input[10];

    while (1) {
        printf("Enter a positive integer or 'quit': ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }
        int value = atoi(input);
        if (value > 0) {
            root = insert(root, value);
        }
    }
    InOrder(root);
    
    return 0;
}
