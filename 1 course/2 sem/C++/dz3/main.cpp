#include "BigInt.cpp"
#include <iostream>
#include <limits>
#include <climits>

int main() {

    cout << LLONG_MAX << endl;
    for (long long i = 1e9 - 100; i <= 1e9; ++i) {
        BigInteger<char, 8> a(i);
        if (!a.check())  {
            cout << "T R O U B L E \n" << i;
            break;
        } else {
            cout << i <<" passed \n";
        }
    }

    bool t = true;

    for (long long i = 1e11 ; i < 1e11 + 500; ++i) {
        for (long long j = 1e6; j < 1e6 + 500; ++j) {
            BigInteger <char, 8> a(i), b(j);
            a *= b;
            long long ans = i * j;
            if (to_string(ans) == a.toString()) {
                cout << a <<" passed\n";
            } else {
                t = false;
                cout <<"T R O U B L E  " << i <<" * " << j << "\n";
                break;
            }
        }
        if (!t) break;
    }



    return 0;
}
