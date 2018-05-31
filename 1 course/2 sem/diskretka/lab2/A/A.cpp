#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

string word;
pair <vector <pair <int, char> >, bool> cond[111111];
ifstream fin("problem1.in");
ofstream fout("problem1.out");

void condition(int i, int ex = 0) {
    if (ex == word.size() && cond[i].second) {
        fout << "Accepts";
        exit(0);
    }
    int &index = ex;
    for (pair <int, char> tr : cond[i].first) {
        if (word[index] == tr.second) {
            condition(tr.first, ex + 1);
        }
    }
}

int main() {
    int n, m, k;
    int num;
	fin >> word;
	fin >> n;
	fin >> m;
	fin >> k;
    for (int i = 0; i < k; i++) {
        fin >> num;
        cond[num - 1].second = true;
    }
    int a, b;
    char c;    
    for (int i = 0; i < m; i++) {
        fin >> a >> b >> c;
        cond[a - 1].first.emplace_back(b - 1, c);
    }
    condition(0);
    fout << "Rejects";
}	
