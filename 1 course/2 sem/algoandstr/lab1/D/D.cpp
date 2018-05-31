#include <iostream>
#include <fstream>

using namespace std;

const int N = static_cast<int>(2e6 + 10);
const int M = static_cast<int>(1e6 + 5);
int n;
char c;
ifstream fin("painter.in");
ofstream fout("painter.out"	);

struct Canvas {
    int length = 0;
    int count = 0;
    bool leftIsBlack = false;
    bool rightIsBlack = false;
    bool updated = false;

    void print() {
        fout << count << ' ' << length << endl;
    }
};

struct Request {
    int isBlack;
    int from;
    int to;

    Request get() {
        char c;
        int x;
        int l;
        fin >> c >> x >> l;
        isBlack = (c == 'B');
        from = x + M;
        to = from + l;
        return *this;
    }

    Request changeTo(int val) {
        Request result = *this;
        result.to = min(to, val);
        return result;
    }

    Request changeFrom(int val) {
        Request result = *this;
        result.from = max(from, val);
        return result;
    }

    Canvas getData(int length) {
        Canvas result;
        if (isBlack) {
            result.leftIsBlack = result.rightIsBlack = true;
            result.count = 1;
            result.length = length;
        } else {
            result.leftIsBlack = result.rightIsBlack = false;
            result.count = result.length = 0;
        }
        result.updated = true;
        return result;
    }
} request;

Canvas operator+(Canvas left, Canvas right) {
    Canvas result;
    result.length = left.length + right.length;
    result.count = left.count + right.count - (left.rightIsBlack && right.leftIsBlack);
    result.leftIsBlack = left.leftIsBlack;
    result.rightIsBlack = right.rightIsBlack;
    return result;
}

struct SegTree {
    int begin;
    int end;
    SegTree *lChild = nullptr;
    SegTree *rChild = nullptr;
    Canvas data;
    SegTree(int begin, int end) {
        this->begin = begin;
        this->end = end;
        build();
    }
    Canvas build() {
        if (end - begin > 1) {
            int mid = (begin + end) / 2;
            return (lChild = new SegTree(begin, mid))->data + (rChild = new SegTree(mid, end))->data;
        }
    }
    void push() {
        if (data.updated) {
            lChild->data = rChild->data = data;
            if (data.length) {
                lChild->data.length = lChild->end - lChild->begin;
                rChild->data.length = rChild->end - rChild->begin;
            }
        }
    }
    Canvas update(Request request) {
        if (request.from >= request.to) {
            return data;
        } else if (request.from == begin && request.to == end) {
            return data = request.getData(end - begin);
        } else {
            push();
            int mid = (begin + end) / 2;
            return data = lChild->update(request.changeTo(mid)) + rChild->update(request.changeFrom(mid));
        }
    };
};

int main() {
    fin >> n;
    SegTree tree(0, N);
    for (int i = 0; i < n; ++i) {
        tree.update(request.get()).print();
    }

}
