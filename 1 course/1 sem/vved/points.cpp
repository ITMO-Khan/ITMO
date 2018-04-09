#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <utility> 
using namespace std;
class Point {
	double x;
	double y;
	double z;
public:
	Point(double a = 0, double b = 0, double c = 0) {
		x = a;
		y = b;
		z = c;
	}
	Point operator+(Point &other) {
		return Point (x + other.x,y + other.y,z + other.z);
	}
	Point operator-(Point &other) {
		double b1 = x - other.x;
		double b2 = y - other.y;
		double b3 = z - other.z;
		Point d(b1, b2, b3);
		return d;
	}
	Point operator*(Point &other) {
		double b1 = x * other.x;
		double b2 = y * other.y;
		double b3 = z * other.z;
		Point d(b1, b2, b3);
		return d;
	}
	Point operator/(double t) {
		double b1 = x / t;
		double b2 = y / t;
		double b3 = z / t;
		Point d(b1, b2, b3);
		return d;
	}
	double len() {
		double t = sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
		return t;
	}
	void Print() {
		cout << this->x << " " << this->y << " " << this->z << endl;
	}
	Point operator*(double num){
		return Point (x * num, y * num, z * num);
	}
};

Point Vector(Point a, Point b) {
	return b - a;
}

double LENGTH(Point a, Point b) {
	Point c = Vector(a,b);
	return c.len();
}
Point Centr(Point a, Point b, Point c) {
	return (a + b + c) / 3;
}

int main() {
	double x, y, z;
	cin >> x >> y >> z;
	Point a(x, y, z);
	cin >> x >> y >> z;
	Point b(x, y, z);
	cin >> x >> y >> z;
	Point c(x, y, z);
	Point d = Centr(a, b, c);
	d.Print();
	double t = LENGTH(a, b);
	Point e = Vector(a, b);
	e.Print();
	cout << t;
	return 0;
}
