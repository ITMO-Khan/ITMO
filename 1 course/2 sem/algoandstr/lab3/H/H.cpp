#include <iostream>
#include <vector>
#include <set>

using namespace std;
int a[11111];
typedef pair<size_t, size_t> p;

void dfs(size_t index, vector<vector<p>> &children, vector<set<size_t>> &colours, vector<size_t> &result) {
	for (auto it = children[index].begin(); it != children[index].end(); it++) {
		dfs(it->first, children, colours, result);
		if (colours[index].size() < colours[it->first].size()) {
			colours[index].swap(colours[it->first]);
		}
		colours[index].insert(colours[it->first].begin(), colours[it->first].end());
	}
	result[index] = colours[index].size();
}

int main() {
	ios_base::sync_with_stdio(false); 	
	cin.tie(NULL); 
	size_t n;
	cin >> n;
	
	vector<vector<p>> children(n + 1);
	vector<set<size_t>> colours(n + 1);
	vector<size_t> result(n + 1);
	
	for (size_t i = 1; i <= n; i++) {
		size_t parent, colour;
		cin >> parent >> colour;
		children[parent].push_back({i, colour});
		colours[i].insert(colour);
	}
	
	dfs(0, children, colours, result);
	
	for (size_t i = 1; i <= n; i++) {
	cout << result[i] << " ";
	}
}
