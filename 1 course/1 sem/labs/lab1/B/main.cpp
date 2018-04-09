#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

const int N = 100000000;
pair<int, int> a[N];
int length, id;
map<int, int> index;
ifstream fin("priorityqueue.in");
ofstream fout("priorityqueue.out");

void swiftUp(int i) {
    while (i > 1 && a[i].first < a[i / 2].first) {
        swap(a[i], a[i / 2]);
        swap(index[a[i].second], index[a[i / 2].second]);
        i /= 2;
    }
}

void swiftDown() {
    int ls = 1;
    while (true) {
        int i = ls;
        if ((i * 2 <= length) && a[ls].first > a[i * 2].first) {
            ls = i * 2;
        }
        if ((i * 2 + 1 <= length) && a[ls].first > a[i * 2 + 1].first) {
            ls = i * 2 + 1;
        }
        if (i == ls) {
            break;
        }
        swap(a[i], a[ls]);
        swap(index[a[i].second], index[a[ls].second]);
    }
}

void push() {
    fin >> a[++length].first;
    a[length].second = id;
    index[id] = length;
    swiftUp(length);
}

void extract() {
    if (length < 1) {
        fout << "*\n";
    }
    else {
        fout << a[1].first << "\n";
        swap(a[1], a[length]);
        swap(index[a[1].second], index[a[length--].second]);
        swiftDown();
    }
}

void decrease() {
    int x, y;
    fin >> x >> y;
    int ind = index[x];
    a[ind].first = y;
    swiftUp(ind);
}

int main() {
    string cmd;
    while (fin >> cmd) {
        ++id;
        if (cmd == "push") {
            push();
        }
        else if (cmd == "extract-min") {
            extract();
        }
        else {
            decrease();
        }
    }
    fin.close();
    fout.close();
    return 0;
}
