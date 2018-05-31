#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
	int n, m, k;
	double p[111111];
	ifstream fin("shooter.in");
	ofstream fout("shooter.out");
	fin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		fin >> p[i];
	}
	double ans = 1 - p[k - 1];
	for (int i = 1; i < m; i++){
		ans *= ( 1 - p[k - 1]);
	}
	double a, b;
	for (int i = 0; i < n; i++){
		a = (1 - p[i]);
		for (int j = 1; j < m; j++){
			a *= (1 - p[i]);
		}
		b += a;
	}
	fout << setprecision(13) << ans / b;
}
