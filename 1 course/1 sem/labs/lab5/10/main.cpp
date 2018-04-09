#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("partition.in");
ofstream fout("partition.out");
vector<int> a;
void gen(int n, int k)
{
    if(n == 0)
    {
        int j = 0;
        for(int i : a)
        {
            j++;
            if (j == a.size())
                fout << i;
            else
                fout << i << '+';
        }
        fout << endl;
        return;
    }
    for(int i = k; i <= n; i++)
    {
        a.push_back(i);
        gen(n - i, i);
        a.pop_back();
    }
}
int main()
{
    int n;
    fin >> n;
    gen(n, 1);
}
