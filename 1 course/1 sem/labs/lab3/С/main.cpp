#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <stack>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("postfix.in");
    stack<long long> ans;
    string s;
    getline(fin,s);
    for (int i = 0; i < s.length(); i ++)
    {
        if ((s[i]=='-') || (s[i]=='+') || (s[i]=='*'))
        {
            if (s[i]=='-') {
                long long a,b;
                a = ans.top();
                ans.pop();
                b = ans.top();
                ans.pop();
                ans.push(b - a);
            }
            if (s[i]=='+') {
                long long a,b;
                a = ans.top();
                ans.pop();
                b = ans.top();
                ans.pop();
                ans.push(a + b);
            }
            if (s[i]=='*') {
                long long a,b;
                a = ans.top();
                ans.pop();
                b = ans.top();
                ans.pop();
                ans.push(a * b);
            }
        } else {
            if (s[i]!=' ')
                ans.push(s[i] - '0');
        }
    }
    fin.close();
    ofstream fout("postfix.out");
    fout<<ans.top();
    fout.close();
}
