#include <stdio.h>
#include "treap.h"

void inorder(TreapNode* root) {
    if (root) {
        inorder(root->left);
        printf("Ключ: %d - Приоритет: %d\n", root->key, root->priority);
        inorder(root->right);
    }
}
