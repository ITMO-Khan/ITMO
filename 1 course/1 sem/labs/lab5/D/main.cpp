#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;
ifstream fin("chaincode.in");
ofstream fout("chaincode.out");
string current;
map<string,int> result;
void chain_code(int n){
    for (int i = 0; i < n; i++){
        current.append("0");
    }
    result[current] = 1;
    while (true){
        fout<<current<<endl;
        string prefix = current;
        prefix.erase(prefix.begin());
        if (result[prefix + "1"]==0){
            current = prefix + "1";
        } else {
            if(result[prefix + "0"]==0){
                current = prefix + "0";
            } else
                break;
        }
        result[current] = 1;
    }
}
int main()
{
    int n;
    fin >> n;
    chain_code(n);;
    return 0;
}
