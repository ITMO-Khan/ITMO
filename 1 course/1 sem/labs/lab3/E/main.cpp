#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int s[1000000];
int n;
pair<int, pair<int, int> > a[1000000];
void unionm(int x,int y){
    if (s[x] == s[y]){
        if (a[x].second.second >= a[y].second.second){
                    a[y].second.second = a[x].second.second;
                } else {
                    a[x].second.second = a[y].second.second;
                }
                if (a[x].second.first <= a[y].second.first){
                    a[y].second.first = a[x].second.first;
                } else {
                    a[x].second.first = a[y].second.first;
                }
        return;

    }else {
        int t = s[y];
        int z = 0;
        for (int i = 0; i <= n; i++) {
            if (s[i] == t){
                s[i] = s[x];
                if (z == 0) {
                    a[x].first+=a[i].first;
                    a[i].first=a[x].first;
                    z++;
                }
                if (a[x].second.second >= a[i].second.second){
                    a[i].second.second = a[x].second.second;
                } else {
                    a[x].second.second = a[i].second.second;
                }
                if (a[x].second.first <= a[i].second.first){
                    a[i].second.first = a[x].second.first;
                } else {
                    a[x].second.first = a[i].second.first;
                }
            }
        }
        t = s[x];
        for (int i = 0; i <= n; i++) {
            if (s[i] == t){
                s[i] = s[y];
                if (a[y].first>a[i].first) {
                    a[i].first=a[y].first;
                } else {
                    a[y].first=a[i].first;
                }
                if (a[y].second.second >= a[i].second.second){
                    a[i].second.second = a[y].second.second;
                } else {
                    a[y].second.second = a[i].second.second;
                }
                if (a[y].second.first <= a[i].second.first){
                    a[i].second.first = a[y].second.first;
                } else {
                    a[y].second.first = a[i].second.first;
                }
            }
        }
    }
}
int main()
{
    ifstream fin("dsu.in");
    ofstream fout("dsu.out");
    fin >> n;
    for (int i = 0; i <= n; i++){
        s[i] = i;
    }
    for (int i = 0; i <=n; i++){
        a[i].first = 1;
        a[i].second.first = i;
        a[i].second.second = i;
    }
    string ss;
    while(fin>>ss){
        if (ss == "union"){
            int x, y;
            fin>>x>>y;
            unionm(x,y);
        }
        if (ss ==  "get"){
            int x;
            fin >> x;
            fout << a[x].second.first << ' '<< a[x].second.second <<' ' << a[x].first << endl;
        }
    }
    fout.close();
    fin.close();
}
