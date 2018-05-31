#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[111111];

struct Answer {
    int parent = -1;
    int lChild = -1;
    int rChild = -1;

    void print() {
        cout << parent + 1 << ' ' <<  lChild + 1 << ' ' << rChild + 1 << endl;
    }
};

template<typename T>
struct RowData {
    T x;
    T y;
    int index;

    bool operator<(RowData other) {
        return (x < other.x);
    }
};

template<typename T>
class Treap {
    Treap *lChild, *rChild, *parent;
    RowData<T> data;
    typedef pair<Treap *, Treap *> pointerPair;

    static pointerPair split(Treap *p, T x) {
        if (p == nullptr) {
            return pointerPair(nullptr, nullptr);
        } else if (x < p->data.x) {
            pointerPair shared = split(p->lChild, x);
            p->lChild = shared.second;
            return pointerPair(shared.first, p);
        } else {
            pointerPair shared = split(p->rChild, x);
            p->rChild = shared.first;
            return pointerPair(p, shared.second);
        }
    };

    static Treap *merge(Treap *left, Treap *right) {
        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else if (left->data.y < right->data.y) {
            left->rChild = merge(left->rChild, right);
            return left;
        } else {
            right->lChild = merge(left, right->lChild);
            return right;
        }
    }

public:
    explicit Treap(RowData<T> data) : data(data), lChild(nullptr), rChild(nullptr), parent(nullptr) {}

    static Treap *insert(Treap *root, Treap *&toAdd) {
        if (root != nullptr) {
            if (toAdd->data.y > root->data.y) {
                toAdd->parent = root;
                toAdd->lChild = root->rChild;
                if (toAdd->lChild != nullptr) {
                    toAdd->lChild->parent = toAdd;
                }
                root->rChild = toAdd;
            } else {
                if (root->parent != nullptr) {
                    insert(root->parent, toAdd);
                } else {
                    root->parent = toAdd;
                    toAdd->lChild = root;
                }
            }
        }
        return toAdd;
    }

    static

    void moveOnParent(Treap *&root) {
        while (root->parent != nullptr) {
            root = root->parent;
        }
    }

    static int genAns(Treap *root, vector<Answer> &answer) {
        int index = root->data.index;
        if (root->parent != nullptr) {
            answer[index].parent = root->parent->data.index;
        }
        if (root->lChild != nullptr) {
            answer[index].lChild = genAns(root->lChild, answer);
        }
        if (root->rChild != nullptr) {
            answer[index].rChild = genAns(root->rChild, answer);
        }
        return index;
    }

};

int main() {
    Treap<int> *toAdd = nullptr, *last = nullptr;
    int n;
    cin >> n;
    vector<RowData<int>> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].x >> nodes[i].y;
        nodes[i].index = i;
    }
    sort(nodes.begin(), nodes.end());
    for (auto node : nodes) {
        toAdd = new Treap<int>(node);
        last = Treap<int>::insert(last, toAdd);
    }
    vector<Answer> answers(static_cast<unsigned long>(n));
    Treap<int>::moveOnParent(last);
    Treap<int>::genAns(last, answers);
    cout << "YES" << endl;
    for (auto answer : answers) {
        answer.print();
    }
    for (int i = 0; i < 1111; i++){
    	a[i] = i;
	}
}
