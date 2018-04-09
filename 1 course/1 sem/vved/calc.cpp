#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

int priority(char oper){ 
	if (oper == '+' || oper == '-') 
		return 1; 
	if (oper == '*' || oper == '/') 
		return 2; 
	if (oper == '!')
		return 3;
} 
bool isnumber(string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

long long fact(int N)
{
    if(N < 0)
        return 0;
    if (N == 0) 
        return 1;
    else 
        return N * fact(N - 1); 
}
int main(){
    string ex; 
	stack <string> prn;
	stack <string> tmp;
	string test;
	vector<string> ar;
	getline(cin, test);
	int k = 0;
	test += ' ';
	while (k != test.size()){
		string str;
		if (test[k] == ' '){
			str = test.substr(0, k);
			if (str[0] == ' '){
				str.replace(0, 1, "");
			}
			ar.push_back(str);
			test.replace(0, k, "");
			k = 0;
		}
		k++;
	}
	for (int j = 0; j < ar.size(); j++){
		ex = ar[j];
		if (isnumber(ex))
			prn.push(ex); 
		else{ 
			if ((ex.size() > 1) || ((j == ar.size() - 1) && (ex != "!"))) {
				cout << "Written number is incorrect";
				return 0;
			} 
			while (!tmp.empty() && priority(ex[0]) <= priority(tmp.top()[0])) { 
				prn.push(tmp.top()); 
				tmp.pop(); 
			} 
			tmp.push(ex); 
		} 
	}
	while (!tmp.empty()){ 
		prn.push(tmp.top()); 
		tmp.pop(); 
	} 
	stack <long long> result;
	int j = prn.size();
	vector <string> vec;
	for (int i = 0; i < j; i++){
		vec.push_back(prn.top());
		prn.pop();
	}
	for (int i = j - 1; i > -1; i--) { 
		string s = vec[i];
		if (isnumber(s)) { 
			stringstream stream;
			stream.clear();
			stream.str(s);
			int k;
			stream >> k;
			result.push(k); 
		} 
		else{ 
			switch (s[0]){ 
				case'+': {
					long long r = result.top(); 
					result.pop(); 
					long long l = result.top(); 
					result.pop();
					result.push(l + r);
				}
				break; 
				case'-': {
					long long r = result.top(); 
					result.pop(); 
					long long l = result.top(); 
					result.pop();
					result.push(l - r);
				}
				break; 
				case'*': {
					long long r = result.top(); 
					result.pop(); 
					long long l = result.top(); 
					result.pop();
					result.push(l * r);
				}
				break; 
				case'/': {
					long long r = result.top(); 
					result.pop(); 
					long long l = result.top(); 
					result.pop();	
					result.push(long(l / r));
				} 
				break; 
				case'!':{
					long long r = result.top(); 
					result.pop();
					result.push(fact(r));
				}
				break;
			} 
		} 
	} 
	cout << '=' << result.top() << endl;
}
