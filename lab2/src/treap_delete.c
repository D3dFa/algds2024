#include <stdlib.h>
#include "treap.h"

TreapNode* deleteNode(TreapNode* root, int key) {
    if (!root) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            TreapNode* temp = root->right;
            free(root);
            root = temp;
        } else if (!root->right) {
            TreapNode* temp = root->left;
            free(root);
            root = temp;
        } else if (root->left->priority < root->right->priority) {
            root = rotateLeft(root);
            root->left = deleteNode(root->left, key);
        } else {
            root = rotateRight(root);
            root->right = deleteNode(root->right, key);
        }
    }
    return root;
}
