#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int Fib(int i) {
	if (i < 1) return 0;
	if (i == 1) return 1;
	return Fib(i - 1) + Fib(i - 2);
}

int iterative1(int i) {
	int a = 0, b = 1;
	for(int j = 0; j < i; j++) { // iterative method 1
		a = a + b;
        b = a - b;
	}
	return a;
}

int iterative2(int i) {
	vector<int> c;
	c.push_back(0);
	c.push_back(1);
	for (int j = 2; j <= i; j++) { //iterative method 2
		c.push_back(c[j - 1] + c[j - 2]);
	}
	return c[i];
	
}

int main() {
	int i;
	cin >> i;
	cout << Fib(i) << " " << iterative1(i) << " " << iterative2(i);
	return 0;
}
