#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
long long A[100000];
long long B[100000];
long long C[200000];
int main()
{
    int i = 0;
    int n = 0,m = 0;
    ifstream fin("style.in");
    fin>>n;
    for (int k = 0; k < n; k++)
    {
        fin>>A[k];
    }
    fin>>m;
    for (int k = 0; k < m; k++)
    {
        fin>>B[k];
    }
    fin.close();
    long long ansA = A[0];
    long long ansB = B[0];
    int j = 0;
    while ( i + j < n + m - 1){
        if (A[i]<B[j]){
            if (abs(ansA - ansB) > abs(A[i]-B[j])){
                ansA = A[i];
                ansB = B[j];
            }
            i++;
        }
        else{
            if (abs(ansA - ansB) > abs(A[i]-B[j])){
                ansA = A[i];
                ansB = B[j];
            }
            j++;
        }
    }
    ofstream fout("style.out");
    fout<<ansA<<' '<<ansB;
    fout.close();
}
