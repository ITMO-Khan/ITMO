#include <iostream>
#include <fstream>

using namespace std;
int a[17];
int n;
ifstream fin("vectors.in");
ofstream fout("vectors.out");
bool test(){
    for (int i = n-1; i > 0; i--){
        if ((a[i] == 1)&&(a[i - 1] == 1)) return false;
    }
    return true;
}
void print(){
    for (int i = n-1; i > -1; i--){
        fout<<a[i];
    }
    fout<<endl;
}
int main()
{
    fin>>n;
    for (int i = 0; i < n; i++){
        a[i] = 0;
    }
    if (n==1) fout<<2;
    if (n==2) fout<<3;
    if (n==3) fout<<5;
    if (n==4) fout<<8;
    if (n==5) fout<<13;
    if (n==6) fout<<21;
    if (n==7) fout<<34;
    if (n==8) fout<<55;
    if (n==9) fout<<89;
    if (n==10) fout<<144;
    if (n==11) fout<<233;
    if (n==12) fout<<377;
    if (n==13) fout<<610;
    if (n==14) fout<<987;
    if (n==15) fout<<1597;
    if (n==16) fout<<2584;
    fout<<endl;
    while (a[n] != 1){
        if (test()==true) print();
        int i = 0;
        while (a[i] == 1){
            a[i] = 0;
            i++;
        }
        a[i]=1;
    }
}
