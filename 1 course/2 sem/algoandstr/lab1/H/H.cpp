#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

unsigned n, m;
ifstream fin("rmq.in");
ofstream fout("rmq.out");

template<typename T>
class Request {
    size_t begin, end;
    T value;

public:
    void getFromCin() {
        fin >> begin >> end >> value;
        --begin;
    }

    size_t getBegin() {
        return begin;
    }

    size_t getEnd() {
        return end;
    }

    T getValue() {
        return value;
    }
};

template<typename T>
class Tree {
    size_t begin{}, end{};
    Tree<T> *lChild;
    Tree<T> *rChild;
    T value;
    bool updated;

public:
    size_t size() {
        return end - begin;
    }

    explicit Tree(size_t begin = 0, size_t end = n) {
        this->begin = begin;
        this->end = end;
        value = INT_MIN;
        updated = false;
        if (size() > 1) {
            size_t mid = (begin + end) / 2;
            lChild = new Tree(begin, mid);
            rChild = new Tree(mid, end);
        }
    }

    T update(T value) {
        updated = true;
        return this->value = max(value, this->value);
    }

    void push() {
        if (updated) {
            lChild->update(this->value);
            rChild->update(this->value);
            updated = false;
        }
    }

    T update(size_t begin, size_t end, T value) {
        if (begin >= end) {
            return this->value;
        }
        if (begin == this->begin && end == this->end) {
            return update(value);
        }
        push();
        size_t mid = (this->begin + this->end) / 2;
        return this->value = min(
                lChild->update(begin, min(mid, end), value),
                rChild->update(max(mid, begin), end, value)
        );
    }

    T find(size_t begin, size_t end) {
        if (begin >= end) {
            return INT_MAX;
        }
        if (begin == this->begin && end == this->end) {
            return value;
        }
        push();
        size_t mid = (this->begin + this->end) / 2;
        return min(
                lChild->find(begin, min(mid, end)),
                rChild->find(max(mid, begin), end)
        );
    }

    void printElements() {
        if (size() > 1) {
            push();
            lChild->printElements();
            rChild->printElements();
        } else {
            fout << value << ' ';
        }
    }
};

int main() {
    fin >> n >> m;
    Tree<int> tree;
    vector<Request<int> > requests(m);
    for (auto &request : requests) {
        request.getFromCin();
    }
    for (auto request : requests) {
        tree.update(request.getBegin(), request.getEnd(), request.getValue());
    }
    for (auto request : requests) {
        if (tree.find(request.getBegin(), request.getEnd()) != request.getValue()) {
            fout << "inconsistent";
            return 0;
        }
    }
    fout << "consistent" << endl;
    tree.printElements();
}
