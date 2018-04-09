#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <utility> 
#include <iomanip>
using namespace std;

class Animal {
protected:
	string name;
	int health;
	int speed_attack;
public:
	Animal(string a, int b, int c) 
		: name(a), health(b), speed_attack(c)
	{}
	string print_name() {
		return this->name;
	}
	int print_health() {
		return this->health;
	}
	int print_speed_atack() {
		return this->speed_attack;
	}
	virtual int fight() = 0;
	virtual int get_damage(int a) = 0;
};

class Tiger : public Animal {
private:
	int strength;
	int base_damage;
public:
	Tiger(string a = "", int b = 0, int c = 0, int d = 0, int e = 0)
		: Animal(a, b, c), strength(d), base_damage(e)
	{}
	
	int print_health(){
		return 123;
	}
	
	int print_strength() {
		return this->strength;
	}
	
	int fight() {
		return this->base_damage*this->strength;
	}
	
	int get_damage(int a) {
		this->health = this->health*this->strength;
		this->health = this->health - a;
		return this->health;
	};
	
	friend istream& operator >> (istream& in, Tiger &c1);
};

istream &operator>>(istream & in, Tiger & c1){
	in >> c1.name >> c1.health >> c1.speed_attack >> c1.strength >> c1.base_damage;
	return in;
}

class Rino : public Animal {
private:
	int resist;
	int horn;
public:
	Rino(string a, int b, int c, int d, int e)
		: Animal(a, b, c), resist(d), horn(e)
	{}
	
	int print_horn() {
		return this->horn;
	}
	int fight() {
		int base_damage = 20;
		int damage = base_damage*this->horn;;
		return damage;
	}
	int get_damage(int a) {
		int base_heal = 10;
		this->health = this->health + base_heal*this->horn;
		this->health = this->health - (1 - (this->resist / 100)) * a;
		return this->health;
	};
};

class Bear : public Animal {
private:
	int height;
public:
	Bear(string a, int b, int c, int d)
		: Animal(a, b, c), height(d)
	{}
	
	int print_height() {
		return this->height;
	}
	int fight() {
		this->speed_attack = this->speed_attack*this->height;
		return this->speed_attack;
	}
	int get_damage(int a) {
		int k = rand() % 2;
		if (k == 0) {
			return this->health;
		}
		else {
			return this->health - a;
		}
	};
};

void meeting(Animal* A, Animal* B) {
	int HEALTH1 = A->get_damage(B->fight());
	int HEALTH2 = B->get_damage(A->fight());
	if (HEALTH1 >= 0 && HEALTH2 >= 0 || HEALTH1 <= 0 && HEALTH2 <= 0) {
		cout << "DRAW" << endl;
	}
	else if (HEALTH1 > 0 && HEALTH2 <= 0) {
		cout << A->print_name() << " " << "WIN" << endl;
	}
	else {
		cout << B->print_name() << " " << "WIN" << endl;
	}
}

int main() {
	vector<Animal*> asd;
	Tiger a;
	cin >> a;
	asd.push_back(&a);
	Rino b("Rino", 200, 100, 80, 50);
	asd.push_back(&b);
	Bear c("Bear", 1000, 50, 150);
	asd.push_back(&c);
	
	for (int i = 0; i < 3; i++)
		cout << asd[i]->fight() << "    ";
	meeting(&a, &c);
	meeting(&a, &b);
	meeting(&b, &c);
	return 0;
}
