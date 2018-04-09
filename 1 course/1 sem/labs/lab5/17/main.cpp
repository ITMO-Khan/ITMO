#include <iostream>
#include <string>
#include <fstream>
using namespace std;
long long d[10000][1000];
int main()
{
    ifstream fin("num2brackets.in");
    ofstream fout("num2brackets.out");
    int n;
    long long k;
    cin >> n >> k;
    k++;
    for (int i = 0; i <= n * 2; i++)
        for (int j = 0; j <= n * 2; j++)
            d[i][j] = 0;
    d[0][0] = 1;
    for (int i = 1; i <= n * 2; i++)
        for (int j = 0; j <= n * 2; j++) {
            if (j > 0){
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
                cout <<d[i][j]<< ' ';
            }
            else {
                d[i][j] = 0 + d[i - 1][j + 1];
                cout <<d[i][j]<< ' ';
            }
	}
    long long depth = 0;
    string s = "";
    for (int i = 0; i <= 2 * n - 1; i++)
        if (d[2 * n - (i + 1)][depth + 1] >= k){
            s += '(';
            depth++;
        }else {
            k -= d[2 * n - (i + 1)][depth + 1];
            s += ')';
            depth--;
        }
    cout << endl;
    cout << s;
}
