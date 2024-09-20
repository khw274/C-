#include <iostream>
using namespace std;

class Photon_Cannon {
	// 멤버 변수
	int hp;
	int shield;
	int coord_x, coord_y;
	int damage;

public:  // 멤버 함수, 생성자
	Photon_Cannon(int x, int y);
	Photon_Cannon(const Photon_Cannon& pc);  // 참조자(레퍼런스) 사용
	
	void show_status();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {  // 복사 생성자, Photon_Cannon의 객체 pc를 상수 레퍼런스로 받음
														 // const 이기 때문에 pc의 데이터를 변경할 수 없음
														 // 복사 생성자 내부에서 데이터 변경 불가, 새롭게 초기화 되는 인스턴스 변수에게 복사만 가능
	cout << "복사 생성자 호출!" << "\n";

	// 인스턴스 변수
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
}

// 인자로 받는 변수의 내용을 함수 내부에서 바꾸지 않는다면 앞에 const를 붙여주는것 이 바람직

Photon_Cannon::Photon_Cannon(int x, int y) {
	cout << "생성자 호출!" << "\n";
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
}

void Photon_Cannon::show_status() {
	cout << "Photon_Cannon : " << "\n";
	cout << "Location : (" << coord_x << " , " << coord_y << " ) " << "\n";
	cout << "HP : " << hp << "\n";
}

int main() {
	Photon_Cannon pc1(3, 3);  // pc1 객체 생성, 생성자 오버로딩
	Photon_Cannon pc2(pc1);   // 인자 pc1을 넘겨 복사 생성자 호출
	Photon_Cannon pc3 = pc2;  // 인자 pc2를 넘겨 pc2 복사 생성자 호출
							  // =  Photon_Cannon pc3(pc2);

	// 복사 생성자는 오직 '생성' 시에만 호출

	pc1.show_status();
	pc2.show_status();
}
