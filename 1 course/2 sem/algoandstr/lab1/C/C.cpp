#include <fstream>
#include <cstdlib>
 
using namespace std;
 
ifstream fin("rmq2.in");
ofstream fout("rmq2.out"); 
long long MAX = 1000000000;

struct ft {
    long long min;
    size_t l;
    size_t r;
    bool t;
    long long add;
    long long set;
};
 
ft* b;
 
long long count(size_t ind) {
    if (b[2 * ind + 1].min < b[2 * ind + 2].min)
        return b[2 * ind + 1].min;
    else
        return b[2 * ind + 2].min;
}
void proSet(size_t cur, long long x) {
    b[cur].t = false;
    b[2 * cur + 1].set = x;
    b[2 * cur + 1].t = true;
    b[2 * cur + 2].set = x;
    b[2 * cur + 2].t = true;
    b[2 * cur + 1].add = 0;
    b[2 * cur + 2].add = 0;
    b[2 * cur + 1].min = x;
    b[2 * cur + 2].min = x;
}
 
void proAdd(size_t cur, long long x) {
    b[cur].add = 0;
    b[2 * cur + 1].add += x;
    b[2 * cur + 2].add += x;
    b[2 * cur + 1].min += x;
    b[2 * cur + 2].min += x;
}
 
long long find(size_t l, size_t r, size_t cur) {
    if (l > b[cur].r || r < b[cur].l) return MAX;
 
    if (l <= b[cur].l && r >= b[cur].r) {
        return b[cur].min;
    }
 
    if (b[cur].t) proSet(cur, b[cur].set);
    if (b[cur].add) proAdd(cur, b[cur].add);
    long long res = min(find(l, r, 2 * cur + 1),
                 find(l, r, 2 * cur + 2));
    b[cur].min = min(b[2 * cur + 1].min, b[2 * cur + 2].min);
    return res;
}
 
 
long long min(long long l, long long r) {
    if (l < r) return l;
    else return r;
}
 
void set(size_t l, size_t r, long long x, size_t cur) {
    if (l > b[cur].r || r < b[cur].l) return;
    if (l <= b[cur].l && r >= b[cur].r) {
        b[cur].t = true;
        b[cur].set = x;
        b[cur].min = x;
        b[cur].add = 0;
        return;
    }
    if (b[cur].t) proSet(cur, b[cur].set);
    proAdd(cur, b[cur].add);
    set(l, r, x, 2 * cur + 1);
    set(l, r, x, 2 * cur + 2);
    b[cur].min = min(b[cur * 2 + 1].min, b[cur * 2 + 2].min);
}
 
void add(size_t l, size_t r, long long x, size_t cur) {
    if (l > b[cur].r || r < b[cur].l) return;
    if (l <= b[cur].l && r >= b[cur].r) {
        b[cur].add += x;
        b[cur].min += x;
        return;
    }
    if (b[cur].t) proSet(cur, b[cur].set);
    proAdd(cur, b[cur].add);
    add(l, r, x, 2 * cur + 1);
    add(l, r, x, 2 * cur + 2);
    b[cur].min = min(b[cur * 2 + 1].min, b[cur * 2 + 2].min);
}
 
int main() {
	MAX = MAX * MAX + 1;
    size_t n;
    fin >> n;
    long long* a = new long long[n];
    for (size_t i = 0; i < n; i++) {
        fin >> a[i];
    }
	size_t v = 1;
    while (n > v) {
        v = v << 1;
    }
    b = new ft[v << 1];
    for (size_t i = 0; i < v << 1; i++) {
        b[i].min = MAX;
        b[i].set = 0;
        b[i].add = 0;
        b[i].l = i;
        b[i].r = i;
        b[i].t = false;
    }
    for (size_t i = 0; i != n; i++) {
        b[v + i - 1].min = a[i];
    }
    for (size_t i = v - 2 + 1; i > 0;) {
        i--;
        b[i].min = min(b[2 * i + 1].min, b[2 * i + 2].min);
        b[i].l = b[2 * i + 1].l;
        b[i].r = b[2 * i + 2].r;
    }
 
    string str;
    while (fin >> str) {
        size_t l, r;
        long long x;
        fin >> l >> r;
        if (str == "min") {
            fout << find(v + l - 2, v + r - 2, 0) << endl;
        }
        else {
            fin >> x;
            if (str == "set") {
                set(v + l - 2, v + r - 2, x, 0);
            }
            else {
                add(v + l - 2, v + r - 2, x, 0);
            }
        }
    }
}
