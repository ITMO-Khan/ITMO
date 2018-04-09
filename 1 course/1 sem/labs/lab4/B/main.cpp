#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    string s;
    ifstream fin("bwt.in");
    string d[1000];
    fin>>s;
    ofstream fout("bwt.out");
    for (int j = 0; j < s.length(); j++){
        for (int i = 0; i < s.length(); i++){
            d[j].push_back(s[(i+j) % s.length()]);
        }
    }
    sort(d, d + s.length());
    for (int j = 0; j < s.length(); j++)
    {
        fout<<d[j][s.length()-1];
    }
}
