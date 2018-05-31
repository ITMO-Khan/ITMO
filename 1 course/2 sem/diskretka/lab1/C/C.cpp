#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

vector< double > c;
int main(){
	ifstream fin("lottery.in");
	ofstream fout("lottery.out");
	int m;
	int a[1111],b[111111];
	double pol, rub = 0;
	double ver = 1;
	double ans;
	fin >> ans >> m;
	for (int i = 0; i < m; i++){
		a[i] = b[i];
	}
	
	for(int i = 0; i < m; i++) {
		fin >> pol;
		ans = ans - rub * ver * (1 - (1 / pol));
		ver = ver / pol;
		fin >> rub;
	}
	ans = ans - rub * ver;
	
	fout << setprecision(8) << ans;
}
