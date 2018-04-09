#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
int main() {
    int a[10000];
    map<string, int> buf;
    string s;
    ifstream fin("lzw.in");
    ofstream fout("lzw.out");
    for (int i = 'a'; i <= 'z'; i++) {
        s.push_back(i);
        buf[s] = i - 'a';
        s = "";
    }
    char c;
    string ss;
    while (fin >> c) {
        ss = s;
        ss.push_back(c);
        if (buf.count(ss)) {
            s = ss;
        }
        else {
            fout << buf[s] << ' ';
            s = "";
            buf[ss] = buf.size();
            s.push_back(c);
        }
    }
    fout << buf[s];
}
