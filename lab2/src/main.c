#include <stdio.h>
#include <stdlib.h>
#include "treap.h"

int main() {
    TreapNode* root = NULL;
    int keys;
    int n = 10;

    for (int i = 0; i < n; i++) {
        keys = rand() % 100;
        root = insert(root, keys);
    }
    root = insert(root, 25);

    inorder(root);

    printf("\nУдаление 25\n");
    root = deleteNode(root, 25);

    inorder(root);

    TreapNode* result = search(root, 25);
    if (result)
        printf("\nКлюч 25 имеет приоритет %d\n", result->priority);
    else
        printf("\nКлюч 25 не найден\n");

    return 0;
}
