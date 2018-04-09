#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm>
using namespace std;
string NumberToString ( long long Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

string to_binary_string(long long x)
{
    string s;
    do
    {
        s.push_back('0' + (x & 1));
    } while (x >>= 1);
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    int n;
    cin >> n;
    long long num[5];
    long long res;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cin >> res;
    if (res == 0){
        cout << "1&~1";
    }
    long long tr = 0;
    long long c = 1;
    string sb;
    string str = to_binary_string(res);
    for (int i = str.length() - 1; i != -1; i--) {
        if (str[i] == '1') {
            long long cur;
            string cursb;
            if ((num[0] & c) > 0)  {
                cur = num[0];
                cursb.append("1");
            }
            else {
                cur = (~num[0]);
                cursb.append("~1");
            }
            for (int j = 1; j != n; j++) {
                if ((num[j] & c) > 0) {
                    cur = cur & num[j];
                    string s;
                    s = NumberToString(j + 1);
                    cursb.append("&" + s);
                }
                else {
                    cur = cur & ~ num[j];
                    string s;
                    s = NumberToString(j + 1);
                    cursb.append("&~" + s);
                }
            }
            tr = tr | cur;
            if (sb.length() != 0) sb.append("|");
            sb.append(cursb);
        }
        c = (c << 1);
    }
    if (tr != res) cout<<"Impossible";
    else cout<<sb;
}
