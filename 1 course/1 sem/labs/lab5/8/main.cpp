#include <iostream>
#include <fstream>
using namespace std;
int n, k, a[20];
ifstream fin("choose.in");
ofstream fout("choose.out");
bool soch()
{
    for (int i = k - 1; i >= 0; --i)
        if (a[i] < n - k + i + 1)
        {
            ++a[i];
            for (int j = i + 1; j < k; ++j)
                a[j] = a[j - 1] + 1;
        return true;
        }
    return false;
}
void print()
{
    for (int i = 0; i < k; i++)
        fout << a[i] << " ";
    fout << endl;
}
int main()
{
    fin >> n >> k;
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    print();
    while (soch())
        print();
}
