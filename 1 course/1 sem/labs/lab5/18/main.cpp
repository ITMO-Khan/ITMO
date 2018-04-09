#include <iostream>
#include <string>
#include <fstream>
using namespace std;
long long d[50][50];
int main()
{
    string s;
    ifstream fin("brackets2num.in");
    ofstream fout("brackets2num.out");
    fin >> s;

    d[0][0] = 1;
    for (int i = 1; i <= 40; i++)
        for (int j = 0; j <= 40; j++) {
            if (j > 0)
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
            else d[i][j] = 0 + d[i - 1][j + 1];
	}

    long long num = 0;
    long long depth = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '(')
            depth++;
        else{
            num += d[s.length() - i - 1][depth + 1];
            depth--;
        }
    }
    fout << num;
}
