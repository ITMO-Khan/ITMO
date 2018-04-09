#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int a[100000000];

int kporyad(int a[], int n, int k)
{
    for (int left=1, right=n; ; )
    {

        if (right <= left+1)
        {
            if ((right == left + 1) && (a[right] < a[left])) {
                swap (a[left], a[right]);
                }
            return a[k];
        }
        int mid = (left + right) >> 1;
        swap (a[mid], a[left + 1]);
        if (a[left] > a[right])
            swap (a[left], a[right]);
        if (a[left + 1] > a[right])
            swap (a[left + 1], a[right]);
        if (a[left] > a[left + 1])
            swap (a[left], a[left + 1]);
        int i = left + 1, j = right;
        const int cur = a[left + 1];
        for (;;)
        {
            while (a[++i] < cur) ;
            while (a[--j] > cur) ;
            if (i > j)
                break;
            swap (a[i], a[j]);
        }
        a[left + 1] = a[j];
        a[j] = cur;
        if (j >= k)
            right = j-1;
        if (j <= k)
            left = i;
    }
}

int main()
{
    ifstream fin("kth.in");
    int n;
    int k;
    fin >> n;
    fin >> k;
    char Astr[100], Bstr[100], Cstr[100], first[100], second[100];
    int A = 0, B = 0, C = 0;
    fin >> Astr >> Bstr >> Cstr >> first >> second;
    A = atoi(Astr);
    B = atoi(Bstr);
    C = atoi(Cstr);
    a[1] = atoi(first);
    a[2] = atoi(second);
    for (int i = 3; i <= n; i++)
    {
        a[i] = A*a[i - 2] + B * a[i - 1] + C;
    }
    fin.close();
    ofstream fout("kth.out");
    fout<<kporyad(a ,n ,k);
    fout.close();
    return 0;
}
