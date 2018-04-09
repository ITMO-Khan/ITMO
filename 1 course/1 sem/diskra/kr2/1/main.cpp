#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int N = 1e5 + 5;

long long fact[20];
vector<int> a;

long long n, m, k, x, y, z;

void print_perm(int m, long long k) {
    if (m > 0) {
        int ans = k / fact[m - 1];
        cout << a[ans] << ' ';
        a.erase(a.begin() + ans);
        print_perm(m - 1, k % fact[m - 1]);
    }
}

int main() {

    fact[0] = 1;
    for (int i = 1; i < 20; ++i) {
        fact[i] = fact[i - 1] * i;
        a.push_back(i);
    }

    cin >> n >> k;

    print_perm(n, k);

    return 0;
}
