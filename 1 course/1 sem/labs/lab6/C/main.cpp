#include <iostream>
#include <fstream>
using namespace std;

typedef long long li;
typedef unsigned long long uli;
const int dxh[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dyh[] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool in(long long i, long long j)
{
    return (i >= 1 && i <= 3 && j >= 1 && j <= 3) || (i == 4 && j == 2);
}
uli dp[111][5][5];
int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            dp[1][i][j] = 1;
    dp[1][3][2] = 0;

    for(int k = 1; k < n; k++)
    {
        for(int i = 1; i <= 4; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                for(int dir = 0; dir < 8; dir++)
                {
                    long long ni = i + dxh[dir];
                    long long nj = j + dyh[dir];

                    if(in(ni, nj))
                    {
                        dp[k + 1][ni][nj] += dp[k][i][j];
                        dp[k + 1][ni][nj] %= 1000000000;
                    }
                }
            }
        }
    }
    uli ans = 0;
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 3; j++){
            ans += dp[n][i][j];
            ans %= 1000000000;
        }
    cout << ans << endl;
    return 0;
}
