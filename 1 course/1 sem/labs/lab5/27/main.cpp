#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string s;
int cl = 0;
int op = 0;
ifstream fin("nextbrackets.in");
ofstream fout("nextbrackets.out");
int main() {
    fin >> s;
    int j = s.size() - 1;
    while (j >= 0) {
        if (s[j] == '(') {
            op++;
            if (cl > op)
                break;
        } else
            if (s[j] == ')')
                cl++;
        j--;
    }
    if (j > 0){
        string ss = "";
        for (int i = 0; i < j; i++){
            ss +=s[i];
        }
        s = ss;
    } else {
        s = "";
    }
    if (s.empty()) {
        fout << '-';
    } else {
        s.push_back(')');
        for (int i = 0; i <= op - 1; i++) {
            s.push_back('(');
        }
        for (int i = 1; i <= cl - 1; i++) {
            s.push_back(')');
        }
        fout << s;
    }
}
