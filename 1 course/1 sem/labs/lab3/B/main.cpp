#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
    ifstream fin("brackets.in");
    stack<char> ans;
    char s;
    ofstream fout("brackets.out");
    while (fin>>s)
    {
        if ((s == '(') || (s == '[') || (s == '{'))
        {
            ans.push(s);
        } else {
            if (!ans.empty()){
                if ((s == ')') && (ans.top() == '(')) {
                    ans.pop();
                }
                if ((s == ']') && (ans.top() == '[')) {
                    ans.pop();
                }
                if ((s == '}') && (ans.top() == '{')) {
                    ans.pop();
                }
            } else {
                fout<<"NO";
                return 0;
            }
        }
    }
    fin.close();
    if (ans.empty()) {
        fout<<"YES";
    } else {
        fout<<"NO";
    }
    fout.close();
}
