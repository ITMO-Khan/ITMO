#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("decode.in");

    stack<char> test;
    test.push('~');
    char s;
    while(fin>>s)
    {
        if (test.top()!=s){
            test.push(s);
        } else {
            test.pop();
        }
    }
    fin.close();
    ofstream fout("decode.out");
    stack<char> ans;
    while(!test.empty()){
        ans.push(test.top());
        test.pop();
    }
    ans.pop();
    while(!ans.empty()){
        fout<< ans.top();
        ans.pop();
    }
    fout.close();

}
