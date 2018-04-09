#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    long long a[2000],c[2000], p[2000], d[2000];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    p[0] = 0;
    for (int i = 0; i < n; ++i) {
        d[i] = 1;
        p[i] = i;
        for (int j = 0; j < i; ++j)
            if (a[j] < a[i])
                if (d[i] < 1 + d[j]){
                    d[i] = 1 + d[j];
                    p[i] = j;
                }
    }
    int ans = d[0];
    int lol = 0;
    for (int i = 0; i < n; ++i) {
        if (ans < d[i]){
            ans = d[i];
            lol = i;
        }
    }
    cout << ans << endl;
    int k = 0;
    for (int i = ans - 1; i >= 0; i--){
        c[k] = a[lol];
        lol = p[lol];
        k++;
    }
    reverse(&c[0], &c[k]);
    for (int i = 0 ; i < k; i++){
        cout << c[i] << ' ';
    }
}
