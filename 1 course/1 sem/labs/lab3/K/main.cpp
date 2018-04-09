#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
deque<int> q_left, q_right;
void eq() {
    while (!q_left.empty() && q_left.size() > q_right.size()) {
        q_right.push_front(q_left.back());
        q_left.pop_back();
    }

    while (!q_right.empty() && q_right.size() - q_left.size() > 1) {
        q_left.push_back(q_right.front());
        q_right.pop_front();
    }
}
int main() {
    int n, m, x, y, z;
    string s;
    ifstream fin("kenobi.in");
    fin >> n;
    ofstream fout("kenobi.out");
    while (fin >> s) {
        if (s == "add") {
            fin >> x;
            q_right.push_back(x);
        }
        else if (s == "take") {
            if (!q_right.empty()) {
                q_right.pop_back();
            }
        }
        else if (s == "mum!") {
            if (q_left.size() + q_right.size() > 1) {
                swap(q_left, q_right);
            }
        }
        eq();
    }
    fout << q_left.size() + q_right.size() << '\n';
    while (!q_left.empty()) {
        fout << q_left.front() << ' ';
        q_left.pop_front();
    }
    while (!q_right.empty()) {
        fout << q_right.front() << ' ';
        q_right.pop_front();
    }
    return 0;
}
