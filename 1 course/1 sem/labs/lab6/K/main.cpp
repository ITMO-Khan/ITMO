#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
ifstream fin("nice.in");
ofstream fout("nice.out");
bool d[1111][1111];
long long a[1111][1111];

bool can_trans(int i, int j, int m) {
	for (int k = 2; k < m; k *= 2) {
		bool lt = i & k / 2, rt = j & k / 2;
		bool lb = i & k, rb = j & k;
		if ((lt + rt + lb + rb) % 4 == 0) {
			return false;
		}
	}
	return true;
}
int n, m, k, x, y, z;
int main() {
	fin >> n >> m;
	if (m > n) {
		x = n;
		n = m;
		m = x;
	}
	m = pow(2, m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			d[i][j] = can_trans(i, j, m);
		}
	}
	for (int i = 0; i < m; i++) {
		a[1][i] = 1;
	}
	for (int len = 1; len < n; len++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				a[len + 1][j] += a[len][i] * d[i][j];
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		ans += a[n][i];
	}
	fout << ans << endl;
	return 0;
}
