#ifndef TREAP_H
#define TREAP_H

typedef struct TreapNode {
    int key;
    int priority;
    struct TreapNode *left, *right;
} TreapNode;

// Функции для работы с Treap
TreapNode* newNode(int key);
TreapNode* rotateRight(TreapNode* y);
TreapNode* rotateLeft(TreapNode* x);
TreapNode* insert(TreapNode* root, int key);
TreapNode* deleteNode(TreapNode* root, int key);
TreapNode* search(TreapNode* root, int key);
void inorder(TreapNode* root);

#endif // TREAP_H
