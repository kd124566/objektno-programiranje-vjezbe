#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Enemy {
protected:
	string name;
	int health;
	int damage;
public:

	Enemy(const string name, int health, int damage) : name(name) {
		if (health < 0) {
			throw invalid_argument("Health mora biti vece od 0!");
		}
		if (damage < 0) {
			throw invalid_argument("Damage mora biti vece od 0!");
		}
		this->health = health;
		this->damage = damage;
	}
	virtual void attack() const {
		cout << "Enemy attacks and has " << damage << " damage!" << endl;
	}

	virtual void displayInfo() const {
		cout << "Enemy " << name << endl;
		cout << "Health " << health << endl;
		cout << "Damage " << damage << endl;
	}
};
class Boss : public Enemy {
private:
	string weapon;
public:
	Boss(const string name, int health, int damage, const string weapon) : Enemy(name, health, damage) {
		if (weapon.empty()) {
			throw invalid_argument("Weapon can't be empty!");
		}
		this->weapon = weapon;
	}
	void attack(){
		cout << "Boss attacks with " << weapon << " and has " << damage << endl;
	}
	void displayInfo()  {
		cout << "Boss: " << name << endl;
		cout << "Health " << health << endl;
		cout << "Damage " << damage << endl;
		cout << "Weapon " << weapon << endl;
	}
};
class Monster : public Enemy {
private:
	string ability;
public:
	Monster(const string name, int health, int damage, const string ability) : Enemy(name, health, damage) {
		if (ability.empty()) {
			throw invalid_argument("Ability ne moze biti prazno!");
		}
		this->ability = ability;
	}
	void attack()  {
		cout << "Monster koristi " << ability << endl;
	}
	void displayInfo()  {
		cout << "Monster " << name << endl;
		cout << "Health " << health << endl;
		cout << "Damage " << damage << endl;
		cout << "Ability " << ability << endl;
	}
};

int main() {
	vector<Enemy*> enemies;
	enemies.push_back(new Boss("snake", 100, 20, "poison"));
	enemies.push_back(new Boss("lion", 70, 10, "bite"));
	enemies.push_back(new Monster("crocodile", 50 , 20, "bite"));
	

	for (const Enemy* enemy : enemies) {
		enemy->displayInfo();
		enemy->attack();
		cout << endl;
	}

	for (const Enemy* enemy : enemies) {
		delete enemy;
	}

	return 0;
}


