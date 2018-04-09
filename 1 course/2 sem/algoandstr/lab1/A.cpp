#include <iostream>
#include <vector>

using namespace std;

int t[1111111];

void build (vector<int> a, int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm))
		+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

int main(){
	vector<int> a;
	vector<int> b;
	int n, x, y, aa;
	cin >> n >> x >> y >> aa;
	for (int i = 0; i < n; i++){
		a.push_back((x * aa + y) % 65536);
	}
	build(a, 1, 0, n - 1);
	int m, z, t, bb;
	cin >> m >> z >> t >> bb;
	for (int i = 0; i < n; i++){
		b.push_back((z * bb + t) % 1073741824);
		b[i] %= n;
	}
	int ans = 0;
	for (int i = 0; 2 * i < n; i++){
		ans += sum(1, 0, n - 1, min(b[2 * i], b[2 * i + 1]), max(b[2 * i], b[2 * i + 1]));
	}
	cout << ans;
}
