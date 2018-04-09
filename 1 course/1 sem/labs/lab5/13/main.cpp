#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
bool was[200];
long long fact(int N)
{
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}
vector <long long> permutation;
long long n;
ifstream fin("num2perm.in");
ofstream fout("num2perm.out");
int main()
{
    long long k;
    fin >> n >> k;
    for (int i = 0; i < n; i++){
        permutation.push_back(0);
    }
    for (long long i = 1; i <= n; i++){
        long long alreadyWas = k / fact(n - i);
        k = k % fact(n - i);
        long long curFree = 0;
        for (int j = 1; j <= n; j++){
            if (was[j] == false){
                curFree++;
                if (curFree == alreadyWas + 1){
                    permutation[i] = j;
                    was[j] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++ ){
        fout << permutation[i] << ' ';
    }
}
