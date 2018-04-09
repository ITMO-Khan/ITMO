#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("partition.in");
ofstream fout("partition.out");
vector<int> a;
int ans;
void gen(int n, int k, int num)
{
    if(n == 0)
    {
        int j = 0;
        num++;
        for(int i : a)
        {
            j++;
            if (j == a.size()){
                if ( num == ans )
                    cout << i;
            }else
                if ( num == ans )
                    cout << i << '+';
        }
        //cout << endl;1100110011001100110100
        return;
    }
    for(int i = k; i <= n; i++)
    {
        a.push_back(i);
        gen(n - i, i, num);
        a.pop_back();
    }
}
int main()
{
    int n;
    cin >> n >> ans;
    ans--;
    gen(n, 1, 0);
}
