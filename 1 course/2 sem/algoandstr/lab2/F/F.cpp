#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class AVLTree {
    struct Node {
        Node *lChild, *rChild;
        T key;
        size_t height, size;

        explicit Node(T key) : key(key), lChild(nullptr), rChild(nullptr), height(1), size(1) {}

        static size_t getHeight(Node *p) {
            return (p != nullptr ? p->height : 0);
        }

        static size_t getSize(Node *p) {
            return (p != nullptr ? p->size : 0);
        }

        void fixHeightAndSize() {
            height = max(getHeight(lChild), getHeight(rChild)) + 1;
            size = getSize(lChild) + getSize(rChild) + 1;
        }

        int getFactor() {
            return static_cast<int>(getHeight(rChild) - getHeight(lChild));
        }

        Node *balanceNode() {
            fixHeightAndSize();
            if (getFactor() == 2) {
                if (rChild->getFactor() < 0) {
                    rChild = rChild->rotateRight();
                }
                return rotateLeft();
            }
            if (getFactor() == -2) {
                if (lChild->getFactor() > 0) {
                    lChild = lChild->rotateLeft();
                }
                return rotateRight();
            }
            return this;
        }

        Node *rotateRight() {
            Node *other = this->lChild;
            this->lChild = other->rChild;
            other->rChild = this;
            this->fixHeightAndSize();
            other->fixHeightAndSize();
            return other;
        }

        Node *rotateLeft() {
            Node *other = this->rChild;
            this->rChild = other->lChild;
            other->lChild = this;
            this->fixHeightAndSize();
            other->fixHeightAndSize();
            return other;
        }
    } *root;

    Node *insert(Node *p, T key) {
        if (p == nullptr) {
            return new Node(key);
        }
        if (p->key == key) {
            return p;
        }
        if (key < p->key) {
            p->lChild = insert(p->lChild, key);
        } else {
            p->rChild = insert(p->rChild, key);
        }
        return p->balanceNode();
    }

    T getMax(Node *root, size_t needToMiss) {
        if (needToMiss == 0) {
            return findMin(root)->key;
        } else if (needToMiss < Node::getSize(root->lChild)) {
            return getMax(root->lChild, needToMiss);
        } else if (needToMiss == Node::getSize(root->lChild)) {
            return root->key;
        } else {
            return getMax(root->rChild, needToMiss - Node::getSize(root->lChild) - 1);
        }
    }

    Node *remove(Node *p, T key) {
        if (p == nullptr) {
            return nullptr;
        }
        if (key < p->key) {
            p->lChild = remove(p->lChild, key);
        } else if (key > p->key) {
            p->rChild = remove(p->rChild, key);
        } else {
            Node *left = p->lChild;
            Node *right = p->rChild;
            delete p;
            if (right == nullptr) {
                return left;
            }
            Node *min = findMin(right);
            min->rChild = removeMin(right);
            min->lChild = left;
            return min->balanceNode();
        }
        return p->balanceNode();
    }

    static Node *findMin(Node *p) {
        return (p->lChild != nullptr ? findMin(p->lChild) : p);
    }

    static Node *removeMin(Node *p) {
        if (p->lChild == nullptr) {
            return p->rChild;
        }
        p->lChild = removeMin(p->lChild);
        return p->balanceNode();
    }

public:

    AVLTree() : root(nullptr) {}

    void add(T key) {
        root = insert(root, key);
    }

    T findMax(size_t number) {
        return getMax(root, root->size - number);
    }

    void remove(T key) {
        root = remove(root, key);
    }

};
int a[11111];
int main() {
    AVLTree<int> tree;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int c, k;
        cin >> c >> k;
        switch (c) {
            case (+1) :
                tree.add(k);
                break;
            case (0) :
                cout << tree.findMax(k) << endl;
                break;
            case (-1) :
                tree.remove(k);
                break;
        }
    }
}
