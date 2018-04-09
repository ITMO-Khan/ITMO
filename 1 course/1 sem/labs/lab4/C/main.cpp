#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("mtf.in");
    ofstream fout("mtf.out");
    string s;
    fin>>s;
    string alph;
    for (char i = 'a'; i <= 'z'; i++)
    {
        alph.push_back(i);
    }
    int ans;
    for (int i = 0; i < s.length(); i++)
    {
        ans = find(alph.begin(), alph.end(), s[i]) - alph.begin();
        fout << ans + 1<< ' ';
        alph.erase(alph.begin() + ans);
        alph.insert(alph.begin(),s[i]);
    }
}
