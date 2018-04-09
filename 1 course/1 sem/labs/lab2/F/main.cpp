#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
using namespace std;
bool ans[2000][2000];
string to_string(int x, int len) {
    string ans(len, '0');
    for (int i = 1; i <= len; ++i) {
        if (x % 2) {
            ans[len - i] = '1';
        }
        x /= 2;
    }
    return ans;
}
int main() {
    int n, x;
    string s;
    cin >> n;
    for (int i = 0; i < pow(2, n); ++i) {
        cin >> s >> ans[i][0];
    }
    for (int i = 1; i < pow(2, n); ++i) {
        for (int j = 0; j < pow(2, n) - i; ++j) {
            ans[j][i] = ans[j][i - 1] ^ ans[j + 1][i - 1];
        }
    }
    for (int i = 0; i < pow(2, n); ++i) {
        cout << to_string(i, n) << ' ' << ans[0][i] << "\n";
    }
    return 0;
}
