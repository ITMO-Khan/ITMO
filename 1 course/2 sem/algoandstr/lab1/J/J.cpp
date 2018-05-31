#include <iostream>

using namespace std;

const int N = static_cast<const int>(1e5 + 6);

int n, m;

struct Wall {
    static const int neutral = INT32_MAX;
    int val = 0;
    bool needToPush = false;

    int updByChild(int lChild, int rChild) {
        return val = min(lChild, rChild);
    }

    int update(int newVal) {
        needToPush = true;
        return val = max(val, newVal);
    }
};

struct Request {
    enum typeEnum {
        UPD, MIN
    } type;
    int begin, end, updVal;

    Request get() {
        string cmd;
        cin >> cmd >> begin >> end;
        if (cmd[0] == 'd') {
            type = UPD;
            cin >> updVal;
        } else {
            type = MIN;
        }
        --begin;
        return *this;
    }
} request;

struct Answer {
    int minimum, index;

    Answer(int minimum, int index) {
        this->minimum = minimum;
        this->index = index;
    }

    static Answer bestOf(Answer a, Answer b) {
        if (a.minimum < b.minimum) {
            return a;
        } else if (a.minimum > b.minimum) {
            return b;
        } else {
            return {a.minimum, min(a.index, b.index)};
        }
    }

    void print() {
        cout << minimum << ' ' << index + 1 << endl;
    }
} neutral(Wall::neutral, -1);

struct SegTree {
    int begin, end;
    SegTree *lChild, *rChild;
    Wall data;

    SegTree(int begin, int end) {
        this->begin = begin, this->end = end;
        this->lChild = this->rChild = nullptr;
        build();
    }

    int length() {
        return end - begin;
    }

    void print(bool recursive = false, int lvl = 2) {
        for (int i = 0; i < lvl; ++i) {
            cerr << '\t';
        }
        fprintf(stderr, "[%i, %i) = %i ", begin, end, data.val);
        if (data.needToPush) {
            fprintf(stderr, "UPDATED ");
        }
        fprintf(stderr, "\n");

        if (recursive && length() > 1) {
            lChild->print(recursive, lvl + 1);
            rChild->print(recursive, lvl + 1);
        }
    }

    int build() {
        if (length() > 1) {
            int mid = (begin + end) / 2;
            return data.updByChild(
                    (lChild = new SegTree(begin, mid))->data.val,
                    (rChild = new SegTree(mid, end))->data.val
            );
        } else {
            return data.val;
        }
    }

    void push() {
        if (data.needToPush) {
            lChild->data.update(data.val);
            rChild->data.update(data.val);
            data.needToPush = false;
        }
    }

    int update(int begin, int end, int newVal) {
        if (begin >= end) {
            return data.val;
        } else if (begin == this->begin && end == this->end) {
            return data.update(newVal);
        } else {
            push();
            return data.updByChild(
                    lChild->update(begin, min(end, lChild->end), newVal),
                    rChild->update(max(begin, rChild->begin), end, newVal)
            );
        }
    }

    Answer findMin(int begin, int end) {
        if (begin >= end) {
            return neutral;
        } else if (begin == this->begin && end == this->end) {
            if (length() > 1) {
                push();
                if (lChild->data.val == data.val) {
                    return lChild->findMin(begin, min(end, lChild->end));
                } else {
                    return rChild->findMin(max(begin, rChild->begin), end);
                }
            } else {
                return {data.val, begin};
            }
        } else {
            push();
            return Answer::bestOf(
                    lChild->findMin(begin, min(end, lChild->end)),
                    rChild->findMin(max(begin, rChild->begin), end)
            );
        }
    }

    void run(Request request) {
        switch (request.type) {
            case Request::UPD :
                update(request.begin, request.end, request.updVal);
                break;
            case Request::MIN :
                findMin(request.begin, request.end).print();
                break;
        }
    };
};

int main() {
    cin >> n >> m;
    SegTree tree(0, n);
    for (int i = 0; i < m; ++i) {
        tree.run(request.get());
    }
}
