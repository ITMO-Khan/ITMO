#include <iostream>
#include <vector>
using namespace std;
int d[11111][2];
vector< vector<int> > tree;
int get(int i, int j) {
	if (d[i][j] == -1) {
		d[i][j] = j;
		for (int k : tree[i]) {
            if (j == 0){
                int ma = max(get(k, 0), get(k, 1));
                d[i][j] = d[i][j] + ma;
            } else {
                int ma = max(get(k, 0), 0);
                d[i][j] = d[i][j] + ma;
            }
		}
	}
	return d[i][j];
}
int n, m;
int main() {
    cin >> n;
	tree.resize(n);
	for (int i = 0; i < n; i++) {
		d[i][0] = d[i][1] = -1;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x != 0) {
            tree[x - 1].push_back(i);
		}
		else {
			m = i;
		}
	}
	int ans = max(get(m, 0), get(m, 1));
	cout << ans << endl;
}
