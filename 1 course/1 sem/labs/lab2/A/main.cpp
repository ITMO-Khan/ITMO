#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<pair<int, int>, bool> ans;
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ans[make_pair(-x, y)] = ans[make_pair(-y, x)] = true;
    }
    for (int g = -n; g <= n; g++) {
        for (int i = -n; i <= n; i++) {
            for (int j = -n; j <= n; j++) {
                for (int k = -n; k <= n; k++) {
                    if (ans[make_pair(i, j)] && ans[make_pair(j, k)]) {
                        ans[make_pair(i, k)] = true;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[make_pair(-i, i)] && ans[make_pair(i, -i)]) {
            return cout << "YES", 0;
        }
    }
    cout << "NO";
    return 0;
}
