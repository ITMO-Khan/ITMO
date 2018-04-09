#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
long long A[100001];
long long B[100001];
long long C[100001];
long long D[100001];
int main()
{
    int i = 0;
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
    //ifstream fin("style.in");
    cin>>n1;
    for (int k = 0; k < n1; k++)
    {
        cin>>A[k];
    }
    //A[n1] = A[n1 - 1];
    cin>>n2;
    for (int k = 0; k < n2; k++)
    {
        cin>>B[k];
    }
    //B[n2] = B[n2 - 1];
    cin>>n3;
    for (int k = 0; k < n3; k++)
    {
        cin>>C[k];
    }
    //C[n3] = C[n3 - 1];
    cin>>n4;
    for (int k = 0; k < n4; k++)
    {
        cin>>D[k];
    }
    //D[n4] = D[n4 - 1];
    //fin.close();
    long long ansA = A[0];
    long long ansB = B[0];
    long long ansC = C[0];
    long long ansD = D[0];
    int j = 0, k = 0, l = 0;
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
    //ofstream fout("style.out");
    cout<<ansA<<' '<<ansB<<' '<<ansC<<' '<<ansD;
    //fout.close();
}
