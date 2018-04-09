#include <fstream>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;
stack<long long> st;
long long a[1000000];
int sum_k(long long k){
		stack<long long> temp = st;
		long long Res = 0;
		for(long long i = 0; i < k; i++) {
			Res += temp.top();
			temp.pop();
		}
		return Res;
}

int main(){
	ifstream fin("hemoglobin.in");
	ofstream fout("hemoglobin.out");
    char string[100];
    int j = 0;
    a[0] = 0;
	while(fin>>string){
		if(string[0] == '+') {
            st.push(atol(&string[1]));
            j++;
            a[j] = a[j - 1] + atol(&string[1]);
		}
		if(string[0] == '-') {
			fout<<st.top()<<endl;
			st.pop();
			j--;
		}
		if(string[0] == '?'){
            int k = atol(&string[1]);
            fout<<a[j] - a[j - k]<<endl;
		}
	}
	return 0;
}
