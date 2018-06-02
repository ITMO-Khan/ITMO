#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 

const int N = 1e5; 
const int K = 17; 

vector<int> g[N]; 
int a[11111];
int tin[N], tout[N], up[K][N], depth[N]; 
int timer = 0; 

void tr(int v, int p) { 
	depth[v] = depth[p] + 1; 
	up[0][v] = p; 
	tin[v] = timer++; 
	for (int u : g[v]) { 
		if (u != p) { 
			tr(u, v); 
		} 
	} 
	tout[v] = timer++; 
} 

bool check(int v, int u) { 
	return tin[v] <= tin[u] && tout[u] <= tout[v]; 
} 

int lca(int v, int u) { 
	if (check(v, u)) return v; 
	if (check(u, v)) return u; 
	for (int i = K - 1; i >= 0; i--) { 
		if (!check(up[i][v], u)) { 
			v = up[i][v]; 
		} 
	} 
	return check(v, u) ? v : up[0][v]; 
} 

bool cmp(int a, int b) { 
	return tin[a] < tin[b]; 
} 

int main() { 
	ios_base::sync_with_stdio(false); 	
	cin.tie(NULL); 
	size_t n; 
	cin >> n; 
	int s; 
	for (size_t i = 0; i < n; i++) { 
		cin >> up[0][i]; 
		if (--up[0][i] == -2) { 
			up[0][i] = 0; 
			s = i; 
		} else { 
			g[up[0][i]].push_back(i); 
		} 
	} 
	
	tr(s, s); 
	for (int i = 1; i < K; ++i) { 
		for (int v = 0; v < n; ++v) { 
			up[i][v] = up[i - 1][up[i - 1][v]]; 
		} 
	} 
	
	int g; 
	cin >> g; 
	
	for (int i = 0; i < g; i++) { 
		int ki; 
		cin >> ki; 
		vector<int> group(ki); 
		for (int j = 0; j < ki; j++) { 
			cin >> group[j]; 
			group[j]--; 
		} 
		sort(group.begin(), group.end(), cmp); 
		
		int ans = depth[group[0]]; 
		for (int i = 1; i < group.size(); i++) { 
			int lca_ = lca(group[i - 1], group[i]); 
			ans += depth[group[i]] - depth[lca_]; 
		} 
		cout << ans << "\n"; 
	} 
}
