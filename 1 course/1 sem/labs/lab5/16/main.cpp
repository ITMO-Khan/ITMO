#include <iostream>
#include <fstream>
using namespace std;
int c[30][30];
int a[10000000];
int main()
{
    ifstream fin("choose2num.in");
    ofstream fout("choose2num.out");
    int n;
    long long m;
    int k;
    int next = 1;
    fin >> n >> k;
    for (int i = 1; i <= k; i++){
        fin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        if (i > 0) {
            for (int j = 1; j <= n; ++j) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }
    int numOfChoose = 0;
    for (int i = 1; i <= k; i++)
        for  (int j = a[i - 1] + 1; j <= a[i] - 1; j++)
            numOfChoose += c[n - j][k - i];
    fout << numOfChoose;
}
