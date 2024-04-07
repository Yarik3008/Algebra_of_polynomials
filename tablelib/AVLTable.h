#pragma once
#include "Table.h" // Подключаем родительский класс Table

struct AVLNode {
    KeyType key;
    ValueType value;
    int height;
    AVLNode* left;
    AVLNode* right;
    AVLNode* parent; // Указатель на родительский узел

    AVLNode(const KeyType& key, const ValueType& value, AVLNode* parent = nullptr)
        : key(key), value(value), height(1), left(nullptr), right(nullptr), parent(parent) {}
};

class AVLTable : public Table {
private:
    AVLNode* root; // Корень AVL-дерева
    AVLNode* current; // текущий узел AVL-дерева
    int count;
    int pos;

    // Вспомогательные приватные методы для балансировки AVL-дерева
    int getHeight(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalanceFactor(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    void fixHeight(AVLNode* node) {
        int hl = getHeight(node->left);
        int hr = getHeight(node->right);
        node->height = (hl > hr ? hl : hr) + 1;
    }

    AVLNode* rotateRight(AVLNode* node) {
        AVLNode* q = node->left;

        node->left = q->right;
        if (node->left != nullptr) node->left->parent = node;

        q->right = node;
        q->parent = node->parent;
        node->parent = q;

        if (q->parent != nullptr) {
            if (q->parent->left == node) q->parent->left = q;
            else q->parent->right = q;
        }
        else { root = q; }

        fixHeight(node);
        fixHeight(q);
        return q;
}

    AVLNode* rotateLeft(AVLNode* node) {
        AVLNode* p = node->right;

        node->right = p->left;
        if (node->right != nullptr) node->right->parent = node;

        p->left = node;
        p->parent = node->parent;
        node->parent = p;

        if (p->parent != nullptr) {
            if (p->parent->left == node) p->parent->left = p;
            else p->parent->right = p;
        }
        else { root = p; }

        fixHeight(node);
        fixHeight(p);
        return p;
    }

    AVLNode* balance(AVLNode* node) {
        fixHeight(node);
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        else if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }
        return node;
    }

    AVLNode* insertNode(AVLNode* node, const KeyType& key, const ValueType& value, AVLNode* parent = nullptr) {
        if (node == nullptr)
            return new AVLNode(key, value, parent);
        if (key < node->key)
            node->left = insertNode(node->left, key, value, node);
        else if (key > node->key)
            node->right = insertNode(node->right, key, value, node);
        else // Если ключ уже существует, обновляем значение
            node->value = const_cast<ValueType&>(value);
        return balance(node);
    }

    AVLNode* findMin(AVLNode* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    AVLNode* deleteNode(AVLNode* node, const KeyType& key) {
        if (node == nullptr)
            return nullptr;
        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                AVLNode* temp = (node->left != nullptr) ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                }
                else
                    *node = *temp;
                delete temp;
            }
            else {
                AVLNode* temp = findMin(node->right);
                node->key = temp->key;
                node->value = temp->value;
                node->right = deleteNode(node->right, temp->key);
            }
        }
        if (node == nullptr)
            return nullptr;
        return balance(node);
    }

public:
    AVLTable() : root(nullptr), current(nullptr), count(0), pos(0) {}

    int GetDataCount() const override {
        return count;
    }

    bool IsEmpty() const override {
        return (root == nullptr || count == 0);
    }

    bool IsFull() const override {
        return false;
    }

    ValueType* Find(const KeyType& key) override {
        AVLNode* current = root;
        while (current != nullptr) {
            if (key == current->key)
                return &(current->value);
            else if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }

    void Insert(const KeyType& key, const ValueType& value) override {
        root = insertNode(root, key, value);
        if (current == nullptr)
            current = root;
        count++;
    }

    void Delete(const KeyType& key) override {
        root = deleteNode(root, key);
        count--;
    }

    int Reset() override {
        current = findMin(root);
        return pos = 0;
    }

    bool IsTabEnded() const override {
        return pos >= count;
    }

    int GoNext() override {
        if (pos == count - 1) { return ++pos; }
        if (current == nullptr) { return 0; }

        if (current->right != nullptr) {
            current = current->right;
            while (current->left != nullptr)
                current = current->left;
        }
        else {
            AVLNode* prev = nullptr;
            while (current->parent != nullptr) {
                prev = current;
                current = current->parent;
                if (current->left == prev) { break; }
            }
        }

        if (current->key == KeyType()) { return GoNext(); }

        return ++pos;
    }

    const KeyType& GetKey() const override {
        return current->key;
    }

    const ValueType* GetValuePtr() const override {
        return &current->value;
    }
};