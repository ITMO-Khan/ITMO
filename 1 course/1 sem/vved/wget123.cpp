#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

const string cs = "wget --no-check-certificate -O B.txt 2> A.txt https://vk.com/";
int main(){
	ofstream fout("result.txt");
	while (true){
		ifstream finn("ex.txt");
		string address;
		int i = 0;
		while (finn >> address){
			string s = cs + address;
			system(s.c_str());
			ifstream fin("B.txt");
			string str;
			time_t now1 = time(0);
			fout << "User " << address << ":" << endl;
	   		char* dt1 = ctime(&now1);
	   		fout << "The local date and time is: " << dt1 << endl;
			while (fin >> str){
				size_t ans1 = str.find(">Online</span>");
				size_t ans2 = str.find("pp_last_activity_offline_text");
				if (ans1 != string::npos){
					fout << "online" << endl;
				} else {
					if (ans2 != string::npos)
						fout << "offline" << endl;
				}
			}
			fin.close();
		}
		finn.close();
	}
	fout.close();
	return 0;	
}	
