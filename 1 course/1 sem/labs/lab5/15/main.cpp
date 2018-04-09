#include <iostream>
#include <fstream>
#include <vector>
int c[30][30];
using namespace std;
int main()
{
    ifstream fin("num2choose.in");
    ofstream fout("num2choose.out");
    int n;
    long long m;
    int k;
    vector <int> choose;
    int next = 1;
    fin >> n >> k >> m;
    for (int i = 0; i <= n; ++i) {
        c[i][0] = 1;
        if (i > 0) {
            for (int j = 1; j <= n; ++j) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }
    while (k > 0){
        if (m < c[n - 1][k - 1]){
            choose.push_back(next);
            k = k - 1;
        } else
            m -= c[n - 1][k - 1];
        n = n - 1;
        next = next + 1;
    }
    for (auto i : choose){
        fout << i << ' ';
    }
}
