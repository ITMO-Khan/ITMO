#include <iostream>
#include <fstream>

using namespace std;

int n;
ifstream fin("brackets.in");
ofstream fout("brackets.out");

void gen(int co, int cc, string ans){
    if (co + cc == 2 * n){
        fout << ans << endl;
        return;
    }
    if (co < n)
        gen(co + 1, cc, ans + "(");
    if (co > cc)
        gen(co, cc + 1, ans + ")");
}
int main()
{
    fin >> n;
    gen(0, 0, "");
}
