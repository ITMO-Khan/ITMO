#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
string a;
string d[1111][1111];
int n, m, k, x, y, z, ans = 0;
int main() {
	cin >> a;
	for (int i = 0; i < a.size(); ++i) {
		d[i][i] = "";
	}
	for (int l = 1; l <= a.size(); l++) {
		for (int i = 0; i <= a.size() - l; i++) {
			int j = i + l;
			for (int k = i; k <= j; k++) {
			    string s = d[i][k] + d[k][j];
                if (d[i][j].size() > s.size())
                    d[i][j] = d[i][j];
                else
                    d[i][j] = s;
			}
            if (d[i][j].size() > d[i +1][j].size())
                d[i][j] = d[i][j];
            else
                d[i][j] = d[i + 1][j];
			if (d[i][j].size() > d[i][j - 1].size())
                d[i][j] = d[i][j];
            else
                d[i][j] = d[i][j - 1];
			if ((a[i] == '(' && a[j - 1] == ')') || (a[i] == '[' && a[j - 1] == ']') || (a[i] == '{' && a[j - 1] == '}')) {
				string s = a[i] + d[i + 1][j - 1] + a[j - 1];
                if (d[i][j].size() > s.size())
                    d[i][j] = d[i][j];
                else
                    d[i][j] = s;
			}
		}
	}
	cout << d[0][a.size()].size() << endl;
	return 0;
}
