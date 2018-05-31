#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long t[111111111];
long long a[111111111];

void build (long long v, long long tl, long long tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (v * 2, tl, tm);
		build (v * 2 + 1, tm + 1, tr);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}
long long sum (long long v, long long tl, long long tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (v * 2, tl, tm, l, min(r, tm)) + sum (v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update (long long v, long long tl, long long tr, long long pos, long long new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int main(){
	int n;
	ifstream fin("rsq.in");
	ofstream fout("rsq.out");
	
	fin >> n;
	for (int i = 0; i < n; i++){
		fin >> a[i];
	}
	build(1, 0, n - 1);
	string s;
	while(fin >> s){
		if (s == "sum"){
			long long l,r;
			fin >> l;
			fin >> r;
			fout << sum(1, 0, n - 1, l - 1, r - 1) << endl;
		} else
			if (s == "set"){
				long long p,v;
				fin >> p;
				fin >> v;
				update(1, 0, n - 1, p - 1, v);
			}
	}
}
