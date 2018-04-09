#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
bool mask[11111][11111];
int a[22], d[1 << 18], p[1 << 18], t[1 << 18], index[1 << 18], lift[1 << 18];
int n, w;
ifstream fin("skyscraper.in");
ofstream fout("skyscraper.out");
vector< vector<int> > ans;
void answer(int m) {
    if (m > 0) {
        ans[t[m]].push_back(p[m]);
        answer(m - (1 << p[m]));
    }
}
int main() {
    fin >> n >> w;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    for (int i = 0; i < (1 << n); i++){
        lift[i] = -1;
        index[i] = -1;
        t[i] = -1;
        p[i] = -1;
    }
    lift[0] = 0;
    for (int m = 1; m < (1 << n); m++){
        for (int i = 0; i < n; i++){
            if (m & (1 << i)){
                int testd = d[m - (1 << i)];
                int testp = p[m - (1 << i)];
                int testl = lift[m - (1 << i)];
                int testt = t[m - (1 << i)];
                int testi = index[m - (1 << i)];
                testp = i;
                if (testl < a[i]) {
                    testt = testd++;
                    if (testl < w - a[i]) {
                        testi = testt;
                        testl = w - a[i];
                    }
                }
                else {
                    testt = testp;
                    testl -= a[i];
                }
                if (lift[m] == -1
                    || testd < d[m]
                    || testd == d[m] && testl > lift[m]) {
                    d[m] = testd;
                    p[m] = testp;
                    lift[m] = testl;
                    t[m] = testt;
                    index[m] = testi;
                }
            }
        }
    }
    ans.resize(d[(1 << n) - 1]);
    answer((1 << n) - 1);
    fout << ans.size() << endl;
    for (vector< int > i : ans) {
        fout << i.size();
        for (int j : i) {
            fout << ' ' << j + 1;
        }
        fout << endl;
    }
}
