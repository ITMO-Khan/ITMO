#include <iostream>

using namespace std;

int n,k;

int a[1000000];
void print(){
    for (int k = 0; k < n; k++){
        cout<<a[k];
    }
    cout<<endl;
}
int main()
{
    cin>>n>>k;
    for (int i = 0; i < n; i++){
        a[i] = 0;
    }
    int x = 0;
    while (true){
        for (int i = 0; i < k; i++){
            print();
            a[x] = i;
        }
    }
}
