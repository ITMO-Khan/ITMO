#include <iostream>
#include <algorithm>

using namespace std;

const int N = static_cast<const int>(2e5);

struct Result {
    int count = 0;
    int x = 0;
    int y = 0;

    void print() const {
        printf("%d\n%d %d", count, x, y);
    }
} result;

struct Window {
    int xLeft = 0;
    int xRight = 0;
    int yTop = 0;
    int yBot = 0;

    void get() {
        cin >> xLeft >> yTop >> xRight >> yBot;
    }
} window;

struct Border {
    int x = 0;
    int yBegin = 0;
    int yEnd = 0;
    bool isOpen = false;

    void set(const Window &w, const bool &isOpen) {
        this->yBegin = w.yTop;
        this->yEnd = w.yBot + 1;
        this->isOpen = isOpen;
        if (this->isOpen) {
            x = w.xLeft;
        } else {
            x = w.xRight;
        }
    }
} borders[N];

bool operator<(Border left, Border right) {
    return (left.x < right.x) ||
           (left.x == right.x && (left.isOpen || !right.isOpen));
}

struct Tree {
    const int begin = 0;
    const int end = 0;
    Tree *lChild = nullptr;
    Tree *rChild = nullptr;

    int data = 0;
    int toAdd = 0;

    Tree(const int &begin, const int &end) : begin(begin), end(end) {
        if (size() > 1) {
            int mid = (begin + end) / 2;
            lChild = new Tree(begin, mid);
            rChild = new Tree(mid, end);
        }
    }

    int size() const {
        return end - begin;
    }

    int get() const {
        return data + toAdd;
    }

    void push() {
        if (toAdd == 0) {
            return;
        }
        data += toAdd;
        lChild->update(toAdd);
        rChild->update(toAdd);
        toAdd = 0;
    }

    void update(const int &value) {
        toAdd += value;
    }

    int update(const int &begin, const int &end, const int &value) {
        if (begin >= end) {
            return get();
        } else if (begin == this->begin && end == this->end) {
            update(value);
            return get();
        } else {
            push();
            return data = max(
                    lChild->update(begin, min(lChild->end, end), value),
                    rChild->update(max(lChild->end, begin), end, value)
            );
        }
    }

    int getResult() {
        if (lChild == nullptr) {
            return begin;
        } else {
            push();
            if (lChild->get() == data) {
                return lChild->getResult();
            } else {
                return rChild->getResult();
            }
        }
    }
} tree(-N, N + 1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        window.get();
        borders[i * 2].set(window, true);
        borders[i * 2 + 1].set(window, false);
    }
    sort(borders, borders + n * 2);
    for (int i = 0; i < n * 2; ++i) {
        int addValue = (borders[i].isOpen ? +1 : -1);
        tree.update(borders[i].yBegin, borders[i].yEnd, addValue);
        if (tree.get() > result.count) {
            result.count = tree.get();
            result.x = borders[i].x;
            result.y = tree.getResult();
        }
    }
    result.print();

    return 0;
}
