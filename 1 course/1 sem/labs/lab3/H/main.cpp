#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

const int N = 1e7;
int main() {
    ifstream fin("saloon.in");
    ofstream fout("saloon.out");
    int n, m, x, y, z;
    queue<int> ans;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> x >> y >> z;
        int time = x * 60 + y;
        int wait = z;

        while (!ans.empty() && ans.front() <= time) {
            ans.pop();
        }

        if (ans.size() <= wait) {
            time = time + 20;
            if (!ans.empty()) {
                time = max(time, ans.back() + 20);
            }
            ans.push(time);
        }
        fout << (time / 60) % 24 << ' ' << time % 60 << '\n';
    }

    return 0;
}
