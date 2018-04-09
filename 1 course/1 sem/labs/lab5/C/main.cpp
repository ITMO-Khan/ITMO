#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("antigray.in");
ofstream fout("antigray.out");
int n;
void print(int a[17]){
    for (int j = 0; j < 3; ++j) {
        for (int i = n-1; i > -1; i--){
            fout<<a[i];
        }
        fout<<endl;
        for (int k = 0; k < n; k++) {
                a[k] = (a[k] + 1) % 3;
        }
    }
}
int main()
{
    int a[17];
    fin>>n;
    for (int i = 0; i < n; i++){
        a[i] = 0;
    }
    print(a);
    if (n != 1)
    while ((a[n - 1] != 1) && (a[n] != 2)){
        int i = 0;
        if (a[i] == 1) a[i] = 2;
        if (a[i] == 0) a[i] = 1;
        print(a);
        if (a[i] == 2) {
            while (a[i] == 2){
                a[i] = 0;
                i++;
            }
            a[i]++;
            if (a[n - 1] != 1) print(a);
        }
    }
}
