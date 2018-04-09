#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("INPUT.TXT");
ofstream fout("OUTPUT.TXT");

const int N = 1e3 + 5;
const int INF = 1e9;

struct day {
    int sum = INF;
    int used = 0;
    int prev = 0;
} d[N][N];

day operator+(day a, int b) {
    a.sum += b;
    return a;
}
int a[1111111];
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

long long n;

int main() {
    d[0][0].sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int k = 0; k <= i; k++) {
            if (a[i] > 100) {
                if (k > 0 && min(d[i - 1][k - 1] + a[i], d[i - 1][k + 1])) {
                    d[i][k] = d[i - 1][k - 1] + a[i];
                    d[i][k].prev = k - 1;
                }
                else {
                    d[i][k] = d[i - 1][k + 1];
                    d[i][k].prev = k + 1;
                    d[i][k].used++;
                }
            }
            else {
                if (min(d[i - 1][k] + a[i], d[i - 1][k + 1])) {
                    d[i][k] = d[i - 1][k] + a[i];
                    d[i][k].prev = k;
                }
                else {
                    d[i][k] = d[i - 1][k + 1];
                    d[i][k].prev = k + 1;
                    d[i][k].used++;
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
    cout << d[n][ans].sum << '\n';
    cout << ans << ' ' << d[n][ans].used << '\n';
    print_prev(n, ans, d[n][ans].used);
}
