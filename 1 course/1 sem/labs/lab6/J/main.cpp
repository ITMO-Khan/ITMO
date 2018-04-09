#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int a[11111][11111], dp[11111][11111], d[11111][11111], p[11111][11111];
int n, m;
void print_p(int j, int i = m) {
	if (p[i][j] != j) {
		print_p(p[i][j], i - (1 << j));
	}
	cout << j + 1 << ' ';
}
int main() {
	cin >> n;
	for (int i = 0; i < 1111; i++){
        for (int j = 0; j < 1111; j++){
            dp[i][j] = INT_MAX;
        }
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	m = ((1 << n) - 1);
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			d[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < n; i++) {
		d[1 << i][i] = 0;
		p[1 << i][i] = i;
	}
	int x;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				for (int k = 0; k < n; k++) {
					if ((j != k) && (i & (1 << k))) {
						if ((x = d[i - (1 << k)][j] + a[j][k]) < d[i][k]) {
							d[i][k] = x;
							p[i][k] = j;
						}
					}
				}
			}
		}
	}
	x = 0;
	for (int i = 1; i < n; ++i) {
		if (d[m][i] < d[m][x]) {
			x = i;
		}
	}
	cout << d[m][x] << endl;
	print_p(x);
}
