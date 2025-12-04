#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right;
} Node;

Node *new_node(int k) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->key = k;
    n->left = n->right = NULL;
    return n;
}

Node *insert(Node *root, int k) {
    if (!root) return new_node(k);
    if (k < root->key) root->left  = insert(root->left, k);
    else if (k > root->key) root->right = insert(root->right, k);
    return root;
}

Node *search(Node *root, int k) {
    if (!root || root->key == k) return root;
    if (k < root->key) return search(root->left, k);
    return search(root->right, k);
}

Node *min_node(Node *root) {
    while (root && root->left) root = root->left;
    return root;
}

Node *delete(Node *root, int k) {
    if (!root) return NULL;
    if (k < root->key) root->left  = delete(root->left, k);
    else if (k > root->key) root->right = delete(root->right, k);
    else {
        if (!root->left)  { Node *r = root->right; free(root); return r; }
        if (!root->right) { Node *l = root->left;  free(root); return l; }
        Node *s = min_node(root->right);
        root->key = s->key;
        root->right = delete(root->right, s->key);
    }
    return root;
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main(void) {
    Node *root = NULL;
    int x = 40;

    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(keys)/sizeof(keys[0]);
    for (int i = 0; i < n; i++) root = insert(root, keys[i]);

    printf("In-order (BST): ");
    inorder(root);
    printf("\n");

    printf("Searching %d: %s\n", x, search(root, x) ? "Found" : "Not found");

    root = delete(root, 30);
    printf("After deleting 30, in-order: ");
    inorder(root);
    printf("\n");

    return 0;
}