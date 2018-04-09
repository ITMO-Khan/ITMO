#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("nextperm.in");
ofstream fout("nextperm.out");
vector<int> a,pre,nex;
int n;

int main()
{
    fin >> n;
    for (int i = 0; i < n; i++){
        int x;
        fin >> x;
        a.push_back(x);
    }
    pre = a;
    nex = a;
    int bugp = 0;
    int bugn = 0;
    if (n > 1){
        for (int i = n - 2; i > -1; i--){
            if (pre[i] > pre[i + 1]) {
                int minimum = i + 1;
                if (i < n - 2){
                    /*reverse(pre.begin() + i, pre.end());
                    for (int j = i + 1; j <= n - 1; j++)
                        if ((pre[j] < pre[minimum]) && (pre[j] > pre[i]))
                            minimum = j;
                    swap(pre[i], pre[minimum]);*/
                    break;
                } else {
                    //reverse(pre.begin() + i, pre.end());
                    break;
                }
            }
            if (i == 0) bugn++;
        }
        if (bugn == 0){
            prev_permutation(pre.begin(), pre.end());
            for (int i = 0; i < n; i++){
                fout << pre[i] << ' ';
            }
        } else {
            for (int i = 0; i < n; i++){
                fout << 0 << ' ';
            }
        }
        fout << endl;
        for (int i = n - 2; i > -1; i--){
            if (nex[i] < nex[i + 1]) {
                /*int minimum = i + 1;
                for (int j = i + 1; j <= n - 1; j++)
                    if ((nex[j] < nex[minimum]) && (nex[j] > nex[i]))
                        minimum = j;
                swap(nex[i], nex[minimum]);
                reverse(nex.begin() + i + 1, nex.end() - 1);*/
                break;
            }
            if (i == 0) bugp++;
        }
        if (bugp == 0){
            next_permutation(nex.begin(), nex.end());
            for (int i = 0; i < n; i++)
                fout << nex[i] << ' ';
        } else {
            for (int i = 0; i < n; i++){
                fout << 0 << ' ';
            }
        }
    } else {
        fout << 0 << endl << 0;
    }
}
