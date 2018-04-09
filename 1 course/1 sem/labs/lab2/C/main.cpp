#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int n, x;
string str;
int cou(int x) {
    int ans = 0;
    while (x > 0) {
        ans += x % 2;
        x /= 2;
    }
    return ans;
}
bool t0(string s) {
    return s[0] == '0';
}
bool t1(string s) {
    return s[s.size() - 1] == '1';
}
bool sam(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] == s[s.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}
bool mon(string s) {
    for (int i = 2; i <= s.size(); i *= 2) {
        for (int j = 0; j < s.size(); j += 2 * s.size() / i) {
            if (s.substr(j, s.size() / i) > s.substr(j + s.size() / i, s.size() / i))
                return false;
        }
    }
    return true;
}
bool lin(string s) {
    int ans[100];
    for (int i = 0; i < s.size(); ++i) {
        ans[i] = int(s[i] == '1');
    }
    for (int i = 1; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            ans[j] ^= ans[j + 1];
        }
        if (ans[0] && cou(i) > 1) {
            return false;
        }
    }
    return true;
}
int main() {
    bool zero = true, one = true, s = true, m = true, l = true;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> str;
        zero &= t0(str);
        one &= t1(str);
        s &= sam(str) && x > 0;
        m &= mon(str);
        l &= lin(str);
    }

    cout << (zero || one || s || m || l ? "NO" : "YES");
    return 0;
}
