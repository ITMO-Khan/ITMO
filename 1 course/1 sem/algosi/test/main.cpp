#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout("test.txt");
    for (int i = 100000; i>0; i--)
    {
        fout<<i<<' ';
    }
}
