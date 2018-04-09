#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;
ifstream fin("subsets.in");
ofstream fout("subsets.out");
vector<int> arr, dop;
int x = 0;
vector< vector<int> > ans;
void mnoj(int num, vector<int> dp)
{
    if (num == arr.size())
    {
        ans.push_back(dp);
        x++;
        return;
    }
    mnoj(num + 1, dp);
    stringstream ssm;
    ssm << arr[num];
    string str = ssm.str();
    dp.push_back(arr[num]);
    mnoj(num + 1, dp);
}
int main()
{
    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(i + 1);
    }
    mnoj(0,dop);
    sort(ans.begin(), ans.end(), less< vector<int> >());
    for (auto i : ans)
    {
        for (auto j : i){
            fout << j << ' ';
        }
        fout << endl;
    }
}
