#include <iostream>
#include <fstream>
using namespace std;
int a[100000000];
int b[100000000];
int n;
void merge(int left, int right) {
    if (right == left)
        return;
    if (right - left == 1) {
        if (a[right] < a[left])
            swap(a[right], a[left]);
        retu2rn;
    }
    int m = (right + left) / 2;
    merge(left, m);
    merge(m + 1, right);
    int xl = left;
    int xr = m + 1;
    int cur = 0;
    while (right - left + 1 != cur) {
        if(xl > m)
            b[cur++] = a[xr++];
        else if (xr > right)
            b[cur++] = a[xl++];
        else if (a[xl] > a[xr])
            b[cur++] = a[xr++];
        else b[cur++] = a[xl++];
    }
    for (int i = 0; i < cur; i++)
        a[i + left] = b[i];
}
int main() {
    ifstream fin("sort.in");
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    merge(0, n - 1);
    fin.close();
    ofstream fout("sort.out");
    for (int i = 0; i < n; i++){
        fout << a[i] << " ";
    }
    fout.close();
    return 0;
}
