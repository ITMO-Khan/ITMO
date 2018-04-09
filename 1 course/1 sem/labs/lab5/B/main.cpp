#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <fstream>

using namespace std;

const int N = 10;

stack<string> a, b, c;

int n, m, x, y, z;

int main() {
    a.push("0");
    a.push("1");
    ifstream fin("gray.in");
    ofstream fout("gray.out");
    fin >> n;
    for (int j = n - 1; j > 0; j--) {
        c = a;
        while ( !a.empty() )
        {
            a.pop();
        }
        while (!c.empty()){
            string i = c.top();
            c.pop();
            a.push(i);
        }
        while ( !b.empty() )
        {
            b.pop();
        }
        while ( !a.empty() ) {
            string i = a.top();
            a.pop();
            c.push(i);
            b.push("0" + i);
        }
        while ( !c.empty() ) {
            string i = c.top();
            c.pop();
            a.push(i);
            b.push("1" + i);
        }
        swap(a, b);
    }
    while (!a.empty()){
            string i = a.top();
            a.pop();
            c.push(i);
        }
    while (!c.empty()) {
        fout << c.top() << '\n';
        c.pop();
    }
}
