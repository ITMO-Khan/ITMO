#include <iostream>
using namespace std;
const int N = 1000;
short a[N][N], val[N];
bool solved[N], have = true, ans = true;
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 1) {
                a[i][j] = (a[i][j] - 1) % 2;
            }
        }
    }
    while (have) {
        have = false;
        for (int i = 0; i < k; i++) {
            if (!solved[i]) {
                int cnt = 0, ind;
                for (int j = 0; j < n; j++) {
                    if (a[i][j] * val[j] == 1) {
                        solved[i] = true;
                        break;
                    }
                    if (!val[j] && a[i][j]) {
                        ++cnt, ind = j;
                    }
                }
                if (!solved[i] && cnt == 1) {
                    val[ind] = a[i][ind];
                    have = true;
                }
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        bool cl = false;
        if (!solved[i]) {
            for (int j = 0; j < n; ++j) {
                if (!val[j]) {
                    val[j] = -1;
                }

                cl |= (a[i][j] * val[j] == 1);
            }
            ans &= cl;
        }
    }

    return cout << (ans ? "NO" : "YES"), 0;
}
