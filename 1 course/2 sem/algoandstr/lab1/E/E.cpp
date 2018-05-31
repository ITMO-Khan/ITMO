#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
 
using namespace std;

const int    N = 5 * 1e5 + 7; 
int mdl;
ifstream fin("crypto.in");
ofstream fout("crypto.out");

struct matrix {
    int a, b, c, d;
    matrix() {
        a = 1; b = 0;
        c = 0; d = 1;
    } 
    matrix(int ha, int hb, int hc, int hd) {
        a = ha;
        b = hb;
        c = hc;
        d = hd;
    }
    void inp() {
        fin >> a >> b >> c >> d;
    }
    void otp() {
        fout << a << " " << b << endl << c << " " << d << endl;
    }
};
 
matrix operator*(matrix a, matrix b) {
    matrix ans;
    ans.a = (a.a * b.a + a.b * b.c) % mdl;
    ans.b = (a.a * b.b + a.b * b.d) % mdl;
    ans.c = (a.c * b.a + a.d * b.c) % mdl;
    ans.d = (a.c * b.b + a.d * b.d) % mdl;
    return ans;
}
matrix neutral(1, 0, 0, 1);
 
vector<matrix> a;
vector<matrix> t;
 
void build(int v, int l, int r) {
    if (r - 1 == l) {
        t[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build((v << 1) + 1, l, m);
    build((v << 1) + 2, m, r);
    t[v] = t[(v << 1) + 1] * t[(v << 1) + 2];
}
 
 
 
matrix get(int v, int l, int r, int ql, int qr) {
    if (qr <= l || ql >= r) {
        return neutral;
    }
    if (ql <= l && r <= qr) {
        return t[v];
    }
    int m = (l + r) / 2;
    return get((v << 1) + 1, l, m, ql, qr) *
        get((v << 1) + 2, m, r, ql, qr);
}
 
int main() {
    int n, x, y, m;
    string s;
    fin >> mdl >> n >> m;
    a.resize(N);
    for (int i = 0; i < n; i++) {
        a[i].inp();
    }
    t.resize(4 * n);
    build(0, 0, n);
    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        x--;
        if (y - x == 1) {
            a[x].otp();
            continue;
        }
        else get(0, 0, n, x, y).otp();
    }
}
