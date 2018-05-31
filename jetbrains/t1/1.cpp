#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<long long> dp;
	dp.push_back(2);
	dp.push_back(2);
	int m = 0, n;
	cin >> n;
	int i = 1;
	while (i < n){
		if ( i % 2 == 1) {
			m = m + 2;
		}
		dp.push_back(dp[i] + m);
		i++;
	}	
	cout << dp[i - 1];
}
