#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int dp[1111][1111];
string s1, s2;

int main() {
    fin >> s1;
    fin >> s2;
    int n;
    if (s1.size() >= s2.size()) n = s1.size();
    else n = s2.size();
    for (int i = 0; i <= n; i++) {
        dp[0][i] = dp[i][0] = i;
    }
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            int minn;
            if (dp[i - 1][j] + 1 < dp[i][j - 1] + 1) minn = dp[i - 1][j] + 1;
            else minn = dp[i][j - 1] + 1;
            if (minn < dp[i - 1][j - 1] + (int)(s1[i - 1] != s2[j - 1])) dp[i][j] = minn;
            else dp[i][j] = dp[i - 1][j - 1] + (int)(s1[i - 1] != s2[j - 1]);
        }
    }
    fout << dp[s1.size()][s2.size()];
    return 0;
}
