#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 30;
int n, delay[N], m, tmp, ans[N];
vector<int> edge[N], out[N], s;
string ans_vals;
int value(int i) {
    int val = 0;
    for (int j : edge[i]) {
        delay[i] = max(delay[i], delay[j] + 1);
        val *= 2;
        val += ans[j];
    }
    return val;
}

void solve(int i = 0) {
    if (i == n) {
        ans_vals.push_back('0' + ans[n - 1]);
    }
    else {
        if (edge[i].size()) {
            ans[i] = out[i][value(i)];
            solve(i + 1);
        }
        else {
            ans[i] = 0;
            solve(i + 1);
            ans[i] = 1;
            solve(i + 1);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        if (m == 0) {
            s.push_back(i);
            continue;
        }

        for (int j = 0; j < m; ++j) {
            cin >> tmp;
            edge[i].push_back(tmp - 1);
        }
        for (int j = 0; j < pow(2, m); ++j) {
            cin >> tmp;
            out[i].push_back(tmp);
        }
    }

    solve();
    cout << delay[n - 1] << "\n" << ans_vals;
    return 0;
}
