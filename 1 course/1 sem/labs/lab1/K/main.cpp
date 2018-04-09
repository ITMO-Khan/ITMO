#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

const int N = 10000;
const double BIN = 100000000;
int t[N], v[N];
vector< pair<double, double> > a(N);

int lower(vector< pair<double, double> > &a, pair<double, double> val) {
    int l = 0, r = a.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        a[m].first <= val.first ? l = m : r = m;
    }
    return l;
}

int upper(vector< pair<double, double> > &a, pair<double, double> val) {
    int l = -1, r = a.size() - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        a[m].first < val.first ? l = m : r = m;
    }
    return r;
}

int main() {
    a.clear();
    a.push_back(make_pair(0, 0));
    int l, n;
    ifstream fin("trains.in");
    fin >> l >> n;
    for (int i = 0; i < n; ++i) {
        fin >> t[i] >> v[i];
        a.push_back(make_pair(a.back().first + t[i], a.back().second + t[i] * v[i]));
    }
    double bin_l = 0, bin_r = BIN;
    for (int it = 0; it < 1000; ++it) {
        double m = (bin_l + bin_r) / 2;

        bool crushed = false;
        for (int k = 0; k < n; ++k) {
            pair<double, double> j = a[k];
            j.first += m;

            int i = lower(a, j);
            if (i == n) {
                break;
            }
            if ((a[i].second + ((j.first - a[i].first) * (double)v[i]) - j.second) < (double)l) {
                crushed = true;
                break;
            }
        }
        for (int k = n; k > 0; --k) {
            pair<double, double> i = a[k];
            i.first -= m;

            int j = upper(a, i);
            if (j == 0 && i.first < a[j].first) {
                break;
            }
            if ((i.second+ ((a[j].first - i.first) * (double)v[max(0, j - 1)]) - a[j].second) < (double)l) {
                crushed = true;
                break;
            }
        }
        if (crushed) {
            bin_l = m;
        } else {
            bin_r = m;
        }
    }
    fin.close();
    ofstream fout("trains.out");
    fout << setprecision(3) << fixed << bin_r << "\n";
    fout.close();
    return 0;
}
