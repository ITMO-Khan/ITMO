#include <bits/stdc++.h>
#include <fstream>
using namespace std;
struct node {
    node *left = nullptr;
    node *right = nullptr;
    long long weigth;
};
typedef pair<long long, node*> pin;
set<pin> sorter;
long long ans = 0;
long long n, m;
void dfs(node *i, int delay = 0) {
    if (i != nullptr) {
        if (i->left == nullptr && i->right == nullptr) {
            ans += i.weigth * max(delay, 1);
        }

        dfs(i->left, delay + 1);
        dfs(i->right, delay + 1);
    }
}
int main() {
    ifstream fin("huffman.in");
    ofstream fout("huffman.out");
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> m;
        node *sheet = new node;
        sheet->weigth = m;
        sorter.insert(make_pair(m, sheet));
    }
    while (sorter.size() > 1) {
        pin sheet_l = *sorter.begin();
        sorter.erase(sorter.begin());
        pin sheet_r = *sorter.begin();
        sorter.erase(sorter.begin());
        pin sum = make_pair(sheet_l.first + sheet_r.first, new node);
        sum.second->left = sheet_l.second;
        sum.second->right = sheet_r.second;
        sum.second->weigth = sheet_l.first + sheet_r.first;
        sorter.insert(sum);
    }
    dfs(sorter.begin()->second);
    fout << ans << endl;
    return 0;
}
