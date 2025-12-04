#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node *new_node(int x) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

void preorder(Node *r) {
    if (!r) return;
    printf("%d ", r->data);
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node *r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->data);
    inorder(r->right);
}

void postorder(Node *r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    printf("%d ", r->data);
}

int main(void) {
    Node *root = new_node(1);
    root->left  = new_node(2);
    root->right = new_node(3);
    root->left->left  = new_node(4);
    root->left->right = new_node(5);

    printf("Pre-order  : ");
    preorder(root);
    printf("\n");

    printf("In-order   : ");
    inorder(root);
    printf("\n");

    printf("Post-order : ");
    postorder(root);
    printf("\n");

    return 0;
}