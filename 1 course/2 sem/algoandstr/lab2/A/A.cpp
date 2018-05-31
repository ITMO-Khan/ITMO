#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class BST {
    BST *lChild, *rChild;
    T *data;

public:
    BST() : lChild(nullptr), rChild(nullptr), data(nullptr) {}

    void insert(const T &key) {
        if (data == nullptr) {
            data = new T(key);
        } else if (key < *data) {
            verify(lChild);
            lChild->insert(key);
        } else if (key > *data) {
            verify(rChild);
            rChild->insert(key);
        }

    }

    BST *getMinimal() {
        return (exist(lChild) ? lChild->getMinimal() : this);
    }

    BST *getMaximal() {
        return (exist(rChild) ? rChild->getMaximal() : this);
    }

    void erase(const T &key) {
        if (data == nullptr) {
            return;
        } else if (*data == key) {
            if (!exist(lChild) && !exist(rChild)) {
                data = nullptr;
            } else if (exist(lChild) && !exist(rChild)) {
                data = lChild->data;
                rChild = lChild->rChild;
                lChild = lChild->lChild;
            } else if (!exist(lChild) && exist(rChild)) {
                data = rChild->data;
                lChild = rChild->lChild;
                rChild = rChild->rChild;
            } else {
                if (!exist(rChild->lChild)) {
                    data = rChild->data;
                    rChild = rChild->rChild;
                } else {
                    BST *child = rChild->getMinimal();
                    data = child->data;
                    child->erase(*data);
                }
            }
        } else if (key < *data) {
            verify(lChild);
            lChild->erase(key);
        } else if (key > *data) {
            verify(rChild);
            rChild->erase(key);
        }
    }

    bool exist(BST *tree) {
        return tree != nullptr && tree->data != nullptr;
    }

    bool exist(const T &key) {
        if (data == nullptr) {
            return false;
        } else if (*data == key) {
            return true;
        } else if (key < *data) {
            verify(lChild);
            return lChild->exist(key);
        } else if (key > *data) {
            verify(rChild);
            return rChild->exist(key);
        }
    }

    void verify(BST *&tree) {
        if (tree == nullptr) {
            tree = new BST;
        }
    }

    BST *next(const T &key) {
        if (data == nullptr) {
            return nullptr;
        } else if (*data <= key) {
            if (!exist(rChild)) {
                return nullptr;
            } else {
                return rChild->next(key);
            }
        } else if (*data > key) {
            verify(lChild);
            BST *result = lChild->next(key);
            return (result != nullptr ? result : this);
        }
    }

    BST *prev(const T &key) {
        if (data == nullptr) {
            return nullptr;
        } else if (*data >= key) {
            if (!exist(lChild)) {
                return nullptr;
            } else {
                return lChild->prev(key);
            }
        } else if (*data < key) {
            verify(rChild);
            BST *result = rChild->prev(key);
            return (result != nullptr ? result : this);
        }
    }

    T getKey() {
        return *data;
    }
};
int a[1111111];

int main() {
    BST<int> tree;
    string s;
    for (int i = 0; i < 11111; i++){
    	a[i] = i;
	}
    int x;
    BST<int> *result;
    while (cin >> s >> x) {
        switch (s[0]) {
            case 'i':
                tree.insert(x);
                break;
            case 'd':
                tree.erase(x);
                break;
            case 'e':
                cout << (tree.exist(x) ? "true" : "false") << '\n';
                break;
            case 'n':
                result = tree.next(x);
                cout << (result == nullptr ? "none" : to_string(result->getKey())) << '\n';
                break;
            case 'p':
                result = tree.prev(x);
                cout << (result == nullptr ? "none" : to_string(result->getKey())) << '\n';
                break;
            default:
                break;
        }
    }
}
