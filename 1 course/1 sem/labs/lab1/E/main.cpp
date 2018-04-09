#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("antiqs.in");
    int n;
    int a[100000];
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        swap(a[i], a[i / 2]);
    }
    fin.close();
    ofstream fout("antiqs.out");
    for (int i = 0; i < n; i++)
    {
        fout << a[i] + 1 << ' ';
    }
    fout.close();
    return 0;
}
