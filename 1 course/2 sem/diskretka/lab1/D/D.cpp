#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double n;

vector<vector<double> > vozv(vector<vector<double> > a){
	vector<vector<double> > b;
	int count = 0;
	for (int i = 0; i < n; i++){
		vector<double> p;
		for (int j = 0; j < n; j++){
			double sum = 0;
			for (int k = 0; k < n; k++){
				sum += (a[j][k] * a[k][i]);
			}
			p.push_back(sum);
			if (abs(a[i][j] - sum) < 0.0001)
				count++;
		}
		b.push_back(p);
	}
	if (count == n * n) {
		return b;
	}else{
		vozv(b);
	}
}

void print(vector< vector<double> > a){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(){
	ifstream fin("markchain.in");
	ofstream fout("markchain.out");
	cin >> n;	
	vector<vector<double> > a;
	vector<vector<double> > b,c;
	for (int i = 0; i < n; i++){
		vector<double> p;
		for (int j = 0; j < n; j++){
			double s;
			cin >> s;
			p.push_back(s);
		}
		a.push_back(p);
		p.clear();
	}
	int count = 0;
	while (count != n * n){
		count = 0;
		vector<vector<double> > b;
		for (int i = 0; i < n; i++){
			vector<double> p;
			for (int j = 0; j < n; j++){
				double sum = 0;
				for (int k = 0; k < n; k++){
					sum += (a[j][k] * a[k][i]);
				}
				p.push_back(sum);
				if (abs(a[i][j] - sum) < 0.0001)
					count++;
			}
			b.push_back(p);
			p.clear();
		}
		a = b;
	}/*
	for (int i = 0; i < n; i++){
		vector <double> p;
		for (int j = 0; j < n; j++){
			p.push_back(1 / n);
		}
		b.push_back(p);
		p.clear();
	}
	for (int i = 0; i < n; i++){
		vector<double> p;
		for (int j = 0; j < n; j++){
			double sum = 0;
			for (int k = 0; k < n; k++){
				sum += (b[j][k] * a[k][i]);
			}
			p.push_back(sum);
		}
		c.push_back(p);
		p.clear();
	}*/
	
	for (int i = 0; i < n; i++){
		cout << a[i][i];
		cout << endl;
	}
}
