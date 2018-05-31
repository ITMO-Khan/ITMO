#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int N = static_cast<const int>(1e5 + 5);

int getNext(int i) {
    return (23 * i + 21563) % 16714589;
}

struct log2 {
    void init(int n) {
        data.assign(n, 0);
        for (int i = 1; i < n; ++i) {
            data[i] = data[(i - 1) / 2] + 1;
        }
    }

    int get(int x) {
        return data[x - 1];
    }

    vector<int> data;
};

struct SparseTable {
    SparseTable(vector<int> a) {
        n = a.size();
        logData.init(n);
        data.resize(log(n) + 1);
        for (int i = 0; i < data.size(); ++i) {
            int len = (1 << i);
            data[i].resize(n - (len - 1));
        }

        data[0] = a;
        for (int i = 1; i < data.size(); ++i) {
            int len = (1 << (i - 1));
            for (int j = 0; j < data[i].size(); ++j) {
                data[i][j] = min(data[i - 1][j], data[i - 1][j + len]);
            }
        }
    }

    int getAns(int u, int v) {
        return findMin(min(u, v) - 1, max(u, v));
    }

    int findMin(int begin, int end) {
        int len = log(end - begin);
        return min(data[len][begin], data[len][end - (1 << len)]);
    }
    int log(int n) {
        return logData.get(n);
    }

    int n;
    vector<vector<int> > data;
    log2 logData;
};

int main() {
	ifstream fin("sparse.in");
	ofstream fout("sparse.out");
    int n, m, a1, u, v, ans;
    fin >> n >> m >> a1 >> u >> v;

    vector<int> a(n, a1);
    for (int i = 1; i < n; ++i) {
        a[i] = getNext(a[i - 1]);
    }
    SparseTable table(a);

    for (int i = 1; i < m; ++i) {
        ans = table.getAns(u, v);
        u = ((17 * u + 751 + ans + 2 * i) % n) + 1;
        v = ((13 * v + 593 + ans + 5 * i) % n) + 1;
    }
    fout << u << ' ' << v << ' ' << table.getAns(u, v);
}
