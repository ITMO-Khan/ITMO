#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 10;

vector<string> a, b;

int n, m, k, x, y, z;

void gen_first(int n, string tmp = "0") {
    if (n == 0) {
        a.push_back(tmp);
    }
    else {
        tmp.push_back('0');
        for (int i = 0; i < 3; ++i) {
            tmp.back() = '0' + i;
            gen_first(n - 1, tmp);
        }
    }
}

int main() {

    cin >> n;

    gen_first(n - 1);

    for (auto i : a) {
        for (int j = 0; j < 3; ++j) {
            b.push_back(i);
            for (auto &c : i) {
                c = (c - '0' + 1) % 3 + '0';
            }
        }
    }

    for (auto i : b) {
        cout << i << '\n';
    }
    return 0;
}
