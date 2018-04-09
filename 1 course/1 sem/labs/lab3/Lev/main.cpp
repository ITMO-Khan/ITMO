#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <fstream>

using namespace std;
ifstream fin("INPUT.TXT");
ofstream fout("OUTPUT.TXT");
const int N = 1e3 + 5;
const int INF = 1e9;

vector<int> a;

struct day {
    int sum = INF;
    int used = 0;
    int prev = 0;
} d[N][N];

day operator+(day a, int b) {
    a.sum += b;
    return a;
}

bool min(day a, day b) {
    return a.sum <= b.sum;;
}

void print_prev(int n, int k, int cnt) {
    if (cnt > 0) {
        int prev = d[n][k].prev;
        if (d[n][k].used - d[n - 1][prev].used > 0) {
            print_prev(n - 1, prev, cnt - 1);
            cout << n << '\n';
        }
        else {
            print_prev(n - 1, prev, cnt);
        }
    }
}

int n, m, k, x, y, z;

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    d[0][0].sum = 0;

    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> m;
        for (int k = 0; k <= i; ++k) {
            if (m > 100) {
                if (k > 0 && min(d[i - 1][k - 1] + m, d[i - 1][k + 1])) {
                    d[i][k] = d[i - 1][k - 1] + m;
                    d[i][k].prev = k - 1;
                }
                else {
                    d[i][k] = d[i - 1][k + 1];
                    d[i][k].prev = k + 1;
                    ++d[i][k].used;
                }
            }
            else {
                if (min(d[i - 1][k] + m, d[i - 1][k + 1])) {
                    d[i][k] = d[i - 1][k] + m;
                    d[i][k].prev = k;
                }
                else {
                    d[i][k] = d[i - 1][k + 1];
                    d[i][k].prev = k + 1;
                    ++d[i][k].used;
                }
            }
        }
    }

    int ans = n;
    for (int i = n - 1; i >= 0; --i) {
        if (d[n][i].sum < d[n][ans].sum) {
            ans = i;
        }
    }

    fout << d[n][ans].sum << '\n';
    fout << ans << ' ' << d[n][ans].used << '\n';
    //print_prev(n, ans, d[n][ans].used);

    return 0;
}
