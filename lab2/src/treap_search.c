#include "treap.h"

TreapNode* search(TreapNode* root, int key) {
    if (!root || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}