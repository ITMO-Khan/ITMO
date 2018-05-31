#include <iostream>

using namespace std;

template<typename T>
class AVL {
    AVL *lChild, *rChild;
    T key;
    size_t height;

public:
    explicit AVL(T key) : key(key), lChild(nullptr), rChild(nullptr), height(1) {}

    static size_t getHeight(AVL *p) {
        return (p != nullptr ? p->height : 0);
    }

    int getFactor() {
        return static_cast<int>(getHeight(rChild) - getHeight(lChild));
    }

    void fixHeight() {
        height = max(getHeight(lChild), getHeight(rChild)) + 1;
    }

    AVL *rotateRight() {
        AVL *other = this->lChild;
        this->lChild = other->rChild;
        other->rChild = this;
        this->fixHeight();
        other->fixHeight();
        return other;
    }

    AVL *rotateLeft() {
        AVL *other = this->rChild;
        this->rChild = other->lChild;
        other->lChild = this;
        this->fixHeight();
        other->fixHeight();
        return other;
    }

    AVL *balanceNode() {
        fixHeight();
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

    static AVL *insert(AVL *p, T key) {
        if (p == nullptr) {
            return new AVL(key);
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

    static AVL *findMin(AVL *p) {
        return (p->lChild != nullptr ? findMin(p->lChild) : p);
    }

    static AVL *removeMin(AVL *p) {
        if (p->lChild == nullptr) {
            return p->rChild;
        }
        p->lChild = removeMin(p->lChild);
        return p->balanceNode();
    }

    static AVL *remove(AVL *p, T key) {
        if (p == nullptr) {
            return nullptr;
        }
        if (key < p->key) {
            p->lChild = remove(p->lChild, key);
        } else if (key > p->key) {
            p->rChild = remove(p->rChild, key);
        } else {
            AVL *left = p->lChild;
            AVL *right = p->rChild;
            delete p;
            if (right == nullptr) {
                return left;
            }
            AVL *min = findMin(right);
            min->rChild = removeMin(right);
            min->lChild = left;
            return min->balanceNode();
        }
        return p->balanceNode();
    }

    static bool exist(AVL *p, const T &key) {
        if (p == nullptr) {
            return false;
        } else if (p->key == key) {
            return true;
        } else if (key < p->key) {
            return exist(p->lChild, key);
        } else if (key > p->key) {
            return exist(p->rChild, key);
        }
    }

    static AVL *next(AVL *p, const T &key) {
        if (p == nullptr) {
            return nullptr;
        } else if (p->key <= key) {
            return next(p->rChild, key);
        } else if (p->key > key) {
            AVL *result = next(p->lChild, key);
            return (result != nullptr ? result : p);
        }
    }

    static AVL *prev(AVL *p, const T &key) {
        if (p == nullptr) {
            return nullptr;
        } else if (p->key >= key) {
            return prev(p->lChild, key);
        } else if (p->key < key) {
            AVL *result = prev(p->rChild, key);
            return (result != nullptr ? result : p);
        }
    }

    T getKey() {
        return key;
    }
};
int a[11111];
int main() {
	for (int i = 0; i < 1111; i++){
		a[i] = i;
	}
	AVL<int> *root = nullptr;
    string cmd;
    int x = 0;
    AVL<int> *result;
    while (cin >> cmd >> x) {
        switch (cmd[0]) {
            case 'i':
                root = AVL<int>::insert(root, x);
                break;
            case 'd':
                root = AVL<int>::remove(root, x);
                break;
            case 'e':
                cout << (AVL<int>::exist(root, x) ? "true" : "false") << '\n';
                break;
            case 'n':
                result = AVL<int>::next(root, x);
                cout << (result == nullptr ? "none" : to_string(result->getKey())) << '\n';
                break;
            case 'p':
                result = AVL<int>::prev(root, x);
                cout << (result == nullptr ? "none" : to_string(result->getKey())) << '\n';
                break;
            default:
                break;
        }
    }

    return 0;
}
