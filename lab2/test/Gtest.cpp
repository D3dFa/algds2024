#include <gtest/gtest.h>
extern "C" {
    #include "treap.h"
}

// Тест для создания узла
TEST(TreapTest, CreateNode) {
    TreapNode* node = newNode(10);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->key, 10);
    EXPECT_GE(node->priority, 0);
    EXPECT_LT(node->priority, 100);
    free(node);
}

// Тест для вставки узлов
TEST(TreapTest, InsertNodes) {
    TreapNode* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    TreapNode* node = search(root, 20);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->key, 20);

    node = search(root, 30);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->key, 30);

    free(root);
}

// Тест для удаления узлов
TEST(TreapTest, DeleteNodes) {
    TreapNode* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    root = deleteNode(root, 20);
    TreapNode* node = search(root, 20);
    EXPECT_EQ(node, nullptr);

    node = search(root, 30);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->key, 30);

    free(root);
}

// Тест для поиска узлов
TEST(TreapTest, SearchNodes) {
    TreapNode* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    TreapNode* node = search(root, 20);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->key, 20);

    node = search(root, 40);
    EXPECT_EQ(node, nullptr);

    free(root);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
