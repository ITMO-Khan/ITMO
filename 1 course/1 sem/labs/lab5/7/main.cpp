#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int n;
int a[9];
ifstream fin("permutations.in");
ofstream fout("permutations.out");
void print(){
    for (int i = 0; i < n; i++){
        fout<<a[i]<<' ';
    }
    fout<<endl;
}
int main()
{
    fin>>n;
    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    if (n == 1) { fout << 1; return 0;}
    int i = n - 2;
    print();
    while(true){
        if (a[i] < a[i + 1]){
            for (int m = n - 1; m > i; m--){
                if (a[m] > a[i]) {
                    swap(a[m], a[i]);
                    reverse(a + i + 1, a + n);
                    i = n - 1;
                    print();
                    break;
                }
            }
        }
        i--;
        if (i == -1) break;
    }
    return 0;
}
