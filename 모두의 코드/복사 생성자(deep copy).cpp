#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Photon_Cannon {
	int hp;
	int shield;
	int coord_x, coord_y;
	int damage;

	char* name;

public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(int x, int y, const char* cannon_name);
	Photon_Cannon(const Photon_Cannon& pc);  // 복사 생성자, 레퍼런스

	~Photon_Cannon();  // 소멸자

	void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = NULL;
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {  // deep copy
	// 소멸자 단계에서 런타임 에러를 피하기 위해 name을 동적 할당하여 따로 복사
	cout << "복사 생성자 호출!" << endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;

	name = new char[strlen(pc.name) + 1];  // name만 동적 할당
	strcpy_s(name, strlen(pc.name) + 1, pc.name);
}

Photon_Cannon::Photon_Cannon(int x, int y, const char* cannon_name) {  // 동적 할당
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = new char[strlen(cannon_name) + 1];
	strcpy_s(name, strlen(cannon_name) + 1, cannon_name);
}

Photon_Cannon::~Photon_Cannon(){  // 소멸자
	if (name) {  // 0이 아닌 값은 if문에서 true로 처리
		delete[] name;
	}
}	

void Photon_Cannon::show_status() {
	cout << "Photon Cannon :: " << name << endl;
	cout << "Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
	cout << "HP : " << hp << endl;
}

int main() {
	Photon_Cannon pc1(3, 3, "Cannon");
	Photon_Cannon pc2 = pc1;  // pc2를 인자로 한 복사 생성자 호출

	pc1.show_status();
	pc2.show_status();
}
