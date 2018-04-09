#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("binsearch.in");
    int a[100000];
    int n;
    int m;
    fin>>n;
    for (int i = 0; i < n; i++){
        fin>>a[i];
    }
    fin>>m;
    ofstream fout("binsearch.out");
    int k = 0;
    for (int i = 0; i < m; i++){
        int key = 0;
        fin>>key;
        int l = -1;
        int r = n - 1;
        while (l < r - 1) {
            int mid = (l + r) / 2;
            if (a[mid] < key){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        if (a[r] == key){
            fout<<r + 1<<" ";
        }
        else{
            fout<<-1<<" ";
        }
        k++;
        l = 0;
        r = n;
        while (l < r - 1) {
            int mid = (l + r) / 2;
            if (a[mid] <= key){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        if (a[l] == key){
            fout<<l + 1<<"\n";
        }
        else{
            fout<<-1<<"\n";
        }
        k++;
    }
    fout.close();
    return 0;
}
