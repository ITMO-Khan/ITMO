#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n, x = 1;
int s[1111111], d[1111111], used[1111111];
vector<vector<int>> tree;

void dfs(int v) {
	s[v] = 1;
	used[v] = x;
	for (int i = 0; i < tree[v].size(); i++) {
		if (used[tree[v][i]] != x && d[tree[v][i]] == -1){
			dfs(tree[v][i]);
			s[v] += s[tree[v][i]];
		}
	}
}

int Centr(int v, int size, int res){
	used[v] = x;
	
	bool flag = true;
	for (int i = 0; i < tree[v].size(); i++) {
		if (s[tree[v][i]] > s[v]) {
			if (size - s[v] > size / 2){
				flag = false;
			}
		}else {
			if (s[tree[v][i]] > size / 2){
				flag = false;
			}
		}
	}
	if (flag == true) 
		return v;
	
	for (int i = 0; i < tree[v].size(); i++) {
		if (used[tree[v][i]] != x && d[tree[v][i]] == -1){
			res = Centr(tree[v][i], size, res);	
		}
	}
	return res;
}

void find_tree(int v, int p){
	dfs(v); 
	x++;
	int r = Centr(v, s[v], v); 
	x++;
	d[r] = p;
	for (int i = 0; i < tree[r].size(); i++) {
		if (d[tree[r][i]] == -1){
			find_tree(tree[r][i], r + 1);
		}
	}
}


int main() {
	cin >> n;
	tree.resize(n);
	d[0] = -1;
	for (int i = 1; i < n; i++) {
		d[i] = -1;
		int u, v;
		cin >> u >> v;
		tree[u - 1].push_back(v - 1);
		tree[v - 1].push_back(u - 1);
	}
	
	find_tree(0, 0);
	for (int i = 0; i < n; i++) {
		cout << d[i] << ' ';
	}
	return 0;
}
