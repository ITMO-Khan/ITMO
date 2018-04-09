#include <iostream>
#include <fstream>
long long p[10000000];
long long fact(int N)
{
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}
void full(int N){
    for (int i = 0; i <= N; i++)
        p[i] = fact(i);
}
using namespace std;
int a[10000000];
int main()
{
    ifstream fin("perm2num.in");
    ofstream fout("perm2num.out");
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++){
        fin >> a[i];
    }
    full(n);
    bool was[100000];
    long long numOfPermutation = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a[i] - 1; j++)
            if (was[j] == false)
                numOfPermutation += p[n - i];
    was[a[i]] = true;
    }
    fout << numOfPermutation;
}
