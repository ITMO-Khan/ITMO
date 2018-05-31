#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

ifstream fin("minonpath.in");
ofstream fout("minonpath.out");

unsigned timer = 0, l = 1;
vector<int> height;
int a[1111111];

void dfs(int v, int p, long costval, int h, vector<vector<pair<int, long>>> &G, vector<int> &tin, vector<int> &tout, vector<vector<int>> &up, vector<vector<long>> &cost) {
    tin[v] = ++timer;
    height[v] = h;
    up[v][0] = p;
    cost[v][0] = costval;
    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
        cost[v][i] = min(cost[v][i-1], cost[up[v][i-1]][i-1]);
    }
    for (size_t i=0; i<G[v].size(); ++i) {
        int to = G[v][i].first;
        if (to != p)
            dfs (to, v, G[v][i].second, h + 1, G, tin, tout, up, cost);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b, vector<int> &tin, vector<int> &tout) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

long costcount(int bottom, int top, vector<vector<int>> &up, vector<vector<long>> &cost) {
    int delta = height[bottom] - height[top];
    int current = bottom;
    long costval = 100000000;
    for (int i = 0; delta > 0; i++) {
        if (delta % 2 == 1) {
            costval = min(costval, cost[current][i]);
            current = up[current][i];
        }
        delta = delta >> 1;
    }
    return costval;
}

long minlca(int a, int b, vector<int> &tin, vector<int> &tout, vector<vector<int>> &up, vector<vector<long>> &cost) {
    if (upper(a, b, tin, tout)) {
        return costcount(b, a, up, cost);
    }
    if (upper(b, a, tin, tout)) {
        return costcount(a, b, up, cost);
    }
    int ta = a;
    for (int i = l; i >= 0; --i) {
        if(!upper(up[a][i], b, tin, tout)) {
            a = up[a][i];
        }
    }
    return min(costcount(ta, up[a][0], up, cost), costcount(b, up[a][0], up, cost));
}

int main(int argc, char **argv) {
    unsigned n = 0, m = 0;
    fin >> n;
    vector<vector<pair<int, long>>> G(n, vector<pair<int, long>>());
    for (int i = 1; i < n; i++) {
        int x;
        long y;
    	fin >> x >> y;
        G[--x].push_back(make_pair(i, y));
    }

    while ((1<<l) <= n) {
        ++l;
    }
    vector<int> tin(n), tout(n);
    vector<vector<int>> up(n, vector<int>(l+1));
    vector<vector<long>> cost(n, vector<long>(l+1));
    height.resize(n);
    dfs(0, 0, 0, 0, G, tin, tout, up, cost);

    fin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        fin >> x >> y;

        long res = minlca(--x, --y, tin, tout, up, cost);
        fout <<  res << endl;
    }
    return 0;
}
