#include "treap.h"

TreapNode* insert(TreapNode* root, int key) {
    if (!root) return newNode(key);

    if (key <= root->key) {
        root->left = insert(root->left, key);
        if (root->left->priority > root->priority)
            root = rotateRight(root);
    } else {
        root->right = insert(root->right, key);
        if (root->right->priority > root->priority)
            root = rotateLeft(root);
    }
    return root;
}
