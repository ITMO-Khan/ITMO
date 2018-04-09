#include <iostream>
#include <fstream>
using namespace std;
int n, k;
ifstream fin("nextchoose.in");
ofstream fout("nextchoose.out");
int a[100000],b[100000];
int main()
{
    fin >> n;
    fin >> k;
    for (int i = 0; i < k; i++){
        fin >> a[i];
    }
    for (int i = 0;  i <= k - 1; i++)
        b[i] = a[i];
    b[k] = n + 1;
    int i = k - 1;
    while ((i >= 0) && (b[i + 1] - b[i] < 2))
        i--;
    if (i >= 0) {
        b[i]++;
        for (int j = i + 1; j <= k - 1; j++)
            b[j] = b[j - 1] + 1;
        for (i = 0; i <= k - 1; i++)
            a[i] = b[i];
        for ( i = 0; i <= k - 1; i++){
            fout <<a[i] << ' ';
        }
    } else
        fout << -1;
}
