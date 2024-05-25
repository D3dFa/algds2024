#include <stdlib.h>
#include "treap.h"

TreapNode* newNode(int key) {
    TreapNode* node = (TreapNode*)malloc(sizeof(TreapNode));
    node->key = key;
    node->priority = rand() % 100; // Генерация случайного приоритета
    node->left = node->right = NULL;
    return node;
}
