#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<long long> a;

long long sum(long long l, long long r){
	if (l == 0)
		return a[r]; 
	else
		return a[r] - a[l - 1];
}

int main(){
	vector<long long> b;
	vector<long long> c;
	int n, x, y, aa;
	int m, z, tt, bb;
	ifstream fin("sum0.in");
	ofstream fout("sum0.out");
		
	fin >> n >> x >> y >> aa;
	fin >> m >> z >> tt >> bb;
	
	a.push_back(aa);
	for (int i = 1; i < n; i++){
		a.push_back((x * a[i - 1] + y) % 65536);
	}
	for (int i = 1; i < n; i++){
		a[i] = a[i - 1] + a[i];
	}
	b.push_back(bb);
	c.push_back(b[0] % n);
	for (int i = 1; i < m * 2; i++){
		if (z * b[i - 1] + tt >= 0) 
			b.push_back((z * b[i - 1] + tt) % 1073741824);
		else
			b.push_back(1073741824 + (z * b[i - 1] + tt));	
		c.push_back(b[i] % n);
	}
	long long ans = 0;
	for (int i = 0; i < m; i++){
		ans += sum(min(c[2 * i], c[2 * i + 1]), max(c[2 * i], c[2 * i + 1]));
	}
	fout << ans;
}
