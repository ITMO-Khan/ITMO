#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
int d[100000],a[1000000],p[1000000];
ifstream fin("input.txt");
ofstream fout("output.txt");
int main()
{
    int n,k,num;
    fin >> n >> k;
    for (int i = 2; i < n; i++){
        fin >> a[i];
    }
    d[1] = 0; a[1] = 0; a[n] = 0;
    for (int i = 2; i <= n; ++i){
        int num_max = i - 1;
        for(int j = max(1, i - k); j <= i - 1; ++j)
            if (d[j] > d[num_max]) {
            num_max = j;
        }
        d[i] = d[num_max] + a[i];
        p[i] = num_max;
    }
    fout << d[n];
    int i = n;
    vector<int> ans;
    ans.push_back(i);
    do {
        i = p[i];
        ans.push_back(i);
    }
    while (i > 1);
    fout << endl;
    fout << ans.size() - 1 << endl;
    for(auto i=ans.rbegin();i!=ans.rend();++i)
        fout << *i << ' ';

}
