#include <iostream>
#include <vector>

using namespace std;

vector<string> words;
vector<char> netterm, temp;
vector<string> grammar;

int main(){
	int n;
	char S;
	cin >> n >> S;
	for (int i = 0; i < n; i++){
		char c;
		cin >> c;
		netterm.push_back(c);
		string s;
		cin >> s;
		cin >> s;
		grammar.push_back(s);
		int test = 0;
		for (int j = 0; j < s.length(); j++){
			if (s[j] >= 'A' && s[j] <= 'Z' )
				test = j;
		}
		if (test == 0){
			temp.push_back(' ');
		}else{
			temp.push_back(s[test]);
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++){
		string s;
		cin >> s;
		words.push_back(s);
	}
	return 0;
}
