#include <iostream>
#include <cassert>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    double h1;
    scanf("%d %lf" , &n, &h1);
    double left = 0;
    double right = h1;
    double last = -1;
    while ((right - left) > 0.01 / (n-1)){
        double mid = (left + right) / 2;
        double prev = h1;
        double cur = mid;
        bool aboveGround = cur > 0;
        for (int i = 3; i <= n; i++) {
            double next = 2 * cur - prev + 2;
            aboveGround &= next > 0;
            prev = cur;
            cur = next;
        }
        if (aboveGround) {
            right = mid;
            last = cur;
        } else {
            left = mid;
        }
    }
    printf("%.2f" , last);
    return 0;
}
