#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("formation.in");
    ofstream fout("formation.out");
    pair<int, int> lol[100000];
    int n, m;
    fin>>n>>m;
    for (int i = 1; i <= n; i++){
        lol[i] = make_pair(0, 0);
    }
    for (int z = 0; z < m; z++){
        string s;
        fin>>s;
        int i, j;
        if (s == "left"){
            fin>>i;
            fin>>j;
            lol[i] = make_pair(lol[j].first, j);
            lol[lol[j].first].second = i;
            lol[j].first = i;
        }
        if (s == "right"){
            fin>>i;
            fin>>j;
            lol[i] = make_pair(j, lol[j].second);
            lol[lol[j].second].first = i;
            lol[j].second = i;
        }
        if (s == "leave"){
            fin>>i;
            lol[lol[i].first].second = lol[i].second;
            lol[lol[i].second].first = lol[i].first;
            lol[i] = make_pair(0, 0);
        }
        if (s == "name"){
            fin >> i;
            fout<< lol[i].first << ' ' << lol[i].second << endl;
        }
    }
}
