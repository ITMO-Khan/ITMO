#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
vector<string> s;
map<char, vector<string> > ans;
int main() {
    ifstream fin("radixsort.in");
    int n, m, k;
    fin >> n >> m >> k;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        fin >> s[i];
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            string cur = s[j];
            char sorter = cur[cur.size() - i];
            ans[sorter].push_back(cur);
        }
        s.clear();
        for (auto ans_cur : ans) {
            for (string cur : ans_cur.second) {
                s.push_back(cur);
            }
            ans[ans_cur.first].clear();
        }
    }
    fin.close();
    ofstream fout("radixsort.out");
    for (string cur : s) {
        fout << cur << endl;
    }
    fout.close();
    return 0;
}
