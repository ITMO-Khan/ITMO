#include <iostream>
#include <deque>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ifstream fin("bureaucracy.in");
    ofstream fout("bureaucracy.out");
    int n;
    int m;
    int num;
    fin>>n>>m;
    deque< int > ans;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        fin>>x;
        sum+=x;
        ans.push_back(x);
    }
    if (m >= sum){
        fout<<"-1";
        return 0;
    }
    int i = 0;
    int d = 0;
    num = n;
    while(m>0){
        if ( m >= n)
        {
            d++;
            m -= n;
        } else {
            if (ans.front() > 0) {
                if (ans.front() - 1 == 0) num--;
                int a = ans.front() - 1;
                ans.pop_front();
                ans.push_back(a);
                m--;
            } else {
                    int x = abs(ans.front());
                    ans.pop_front();
                    int y = ans.front() - x;
                    if ((ans.front() > 0) && (y <= 0)) num--;
                    ans.pop_front();
                    ans.push_front(y);
            }
        }
        if (n > m){
            while (i < ans.size()){
                int a = ans.front() - d;
                ans.pop_front();
                ans.push_front(a);
                if (ans.front() <= 0){
                    int x = abs(ans.front());
                    num--;
                    ans.pop_front();
                    int y = ans.front() - x;
                        ans.pop_front();
                    ans.push_front(y);
                    a = y;
                }
                ans.pop_front();
                ans.push_back(a);
                i++;
            }
        }
    }
    fout<<num<<endl;
    while (!ans.empty()){
        if (ans.front() != 0)
            fout<<ans.front()<<' ';
        ans.pop_front();
    }
}
