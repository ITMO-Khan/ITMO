#include <bits/stdc++.h> 
#include <fstream>
using namespace std; 

const int N = 5e4; 
const int K = 16; 

int h[N]; 
int a[11111];

vector<int> g[N]; 
int sa[N], no[N], sz[N], up[K][N], tin[N], tout[N], cnt[N], fath[N]; 

vector<int> paths[N]; 

struct Node { 
	int L, R; 
	Node* l; 
	Node* r; 
	int mx; 
	
	Node() {} 
	Node(int L, int R, const vector<int>& path) : L(L), R(R), l(nullptr), r(nullptr), mx(h[path[L]]) { 
	} 
	Node(Node* l, Node* r) : L(l->L), R(r->R), l(l), r(r), mx(max(l->mx, r->mx)) { 
	} 
}; 

Node* build(int L, int R, const vector<int> &path) { 
	if (R - L == 1) return new Node(L, R, path); 
	int M = (L + R) / 2; 
	return new Node(build(L, M, path), build(M, R, path)); 
} 

void set_value(Node *node, int pos, int val) { 
	if (node->R - node->L == 1) { 
		node->mx = val; 
		return; 
	} 
	if (pos < node->l->R) set_value(node->l, pos, val); 
	else set_value(node->r, pos, val); 
	node->mx = max(node->l->mx, node->r->mx); 
} 

int get_max(Node* node, int L, int R) { 
	if (node->R <= L || R <= node->L) return 0; 
	if (L <= node->L && node->R <= R) return node->mx; 
	return max(get_max(node->l, L, R), get_max(node->r, L, R)); 
} 

int timer = 0; 

void dfs(int v, int p) { 
	up[0][v] = p; 
	for (int i = 1; i < K; ++i) { 
		up[i][v] = up[i - 1][up[i - 1][v]]; 
	} 
	sz[v] = 1; 
	tin[v] = timer++; 
	for (int u : g[v]) { 
		if (u != p) { 
			dfs(u, v); 
			sz[v] += sz[u]; 
		} 	
	} 
	tout[v] = timer++; 
} 

int tc = 0; 

void go(int v, int p) { 
	if (v == p || 2 * sz[v] <= sz[p]) { 
		sa[v] = tc++; 
		fath[sa[v]] = v; 
		no[v] = 0; 
	} else { 
		sa[v] = sa[p]; 
		no[v] = no[p] + 1; 
	} 
	paths[sa[v]].push_back(v); 
	++cnt[sa[v]]; 
	for (int u : g[v]) { 
		if (u != p) { 
		go(u, v); 
		} 
	} 
} 

bool is_anc(int v, int u) { 
	return tin[v] <= tin[u] && tout[u] <= tout[v]; 
} 

int LCA(int v, int u) { 
	if (is_anc(v, u)) return v; 
	if (is_anc(u, v)) return u; 
	for (int i = K - 1; i >= 0; --i) { 
		if (!is_anc(up[i][v], u)) { 
			v = up[i][v]; 
		} 
	} 
	return up[0][v]; 
} 


vector<Node*> tree; 

int get_max_up(int v, int lca) { 
	int ret = 0; 
	while (sa[v] != sa[lca]) { 
		ret = max(ret, get_max(tree[sa[v]], 0, no[v] + 1)); 
		v = up[0][fath[sa[v]]]; 
	} 
	ret = max(ret, get_max(tree[sa[v]], no[lca], no[v] + 1)); 
	return ret; 
	} 
	
int get_max_on_path(int v, int u) { 
	int lca = LCA(v, u); 
	return max(get_max_up(v, lca), get_max_up(u, lca)); 
} 

int main() { 
	ifstream fin("mail.in"); 
	ofstream fout("mail.out"); 
	int n; 
	fin >> n; 
	
	for (int i = 0; i < n; ++i) { 
		fin >> h[i];
	} 
	
	for (int i = 0; i < n - 1; ++i) { 
		int u, v; 
		fin >> u >> v; 
		--u, --v; 
		g[u].push_back(v); 
		g[v].push_back(u); 
	} 
	
	dfs(0, 0); 
	go(0, 0); 
	
	tree.resize(tc); 
	for (int i = 0; i < tc; ++i) { 
		tree[i] = build(0, cnt[i], paths[i]); 
	} 
	
	int k; 
	fin >> k; 
	for (int i = 0; i < k; ++i) { 
		char c; 
		fin >> c; 
		
		if (c == '!') { 
			int v, he; 
			fin >> v >> he; 
			--v; 
			set_value(tree[sa[v]], no[v], he); 
		} else { 
			int u, v; 
			fin >> u >> v; 
			--u, --v; 
			fout << get_max_on_path(u, v) << endl; 
		} 
	} 
}
