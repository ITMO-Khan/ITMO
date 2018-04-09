#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
    ifstream fin("stack-min.in");
    ofstream fout("stack-min.out");
    stack<long long> mstack, minstack;
    long long x, minel;
    int com;
    int n;
    fin>>n;
    for (int i = 0; i < n; i++){
        fin>>com;
        if (com == 1){
            fin>>x;
            if ((!minstack.empty()) && (!mstack.empty())){
                if ( x <= minstack.top() ){
                    minstack.push(x);
                }
                mstack.push(x);

            }else {
                mstack.push(x);
                minstack.push(x);
            }
        }
        if (com == 2){
            if (mstack.top() == minstack.top()){
                minstack.pop();
            }
            mstack.pop();
        }
        if (com == 3){
            fout<<minstack.top()<<endl;
        }
    }
    fin.close();
    fout.close();
}
