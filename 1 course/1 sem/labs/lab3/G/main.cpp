#include <iostream>
#include <fstream>
#include <cmath>
#include <deque>
using namespace std;
deque<int> r;
deque<int> l;
int n;

void distr(int lsize, int rsize){
    if (lsize - rsize >= 0){
        return;
    } else {
        int k;
        l.push_back(r.front());
        r.pop_front();
        rsize--;
        lsize++;
        distr(lsize, rsize);
    }

}
int main()
{
    ifstream fin("hospital.in");
    ofstream fout("hospital.out");
    fin>>n;
    string s;
    for (int i = 0; i < n; i++){
        fin>>s;
        if (s == "+"){
            int x;
            fin>>x;
            r.push_back(x);
            distr(l.size(), r.size());
        }
        if (s == "-"){
            fout<<l.front()<<endl;
            l.pop_front();
            distr(l.size(), r.size());
        }
        if (s == "*"){
            int x;
            fin>>x;
            if (l.size() - r.size() == 1){
                r.push_front(x);
            } else {
                l.push_back(x);
            }
        }
    }
    fin.close();
    fout.close();
}
