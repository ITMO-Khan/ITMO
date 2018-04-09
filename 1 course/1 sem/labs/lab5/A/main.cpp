#include <iostream>
#include <fstream>

using namespace std;
int a[17];
int n;
ifstream fin("allvectors.in");
ofstream fout("allvectors.out");
void print(){
    for (int i = n-1; i > -1; i--){
        cout<<a[i];
    }
    cout<<endl;
}
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++){
        a[i] = 0;
    }
    while (a[n] != 1){
        print();
        int i = 0;
        while (a[i] == 1){
            a[i] = 0;
            i++;
        }
        a[i]=1;
    }
}
