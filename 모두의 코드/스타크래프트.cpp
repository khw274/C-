#include <iostream>
using std::cout;
using std::endl;

class Marine {

	// 멤버 변수
	// 객체의 내부적 성질 및 상태: private
	int hp;								// 체력
	int coord_x, coord_y;						// 위치
	int damage;							// 공격력
	bool is_dead;							// 사망

public:
	
	// 생성자, 멤버 함수
	Marine();							// 디폴트 생성자
	Marine(int x, int y);						// x, y 좌표에 마린 생성
	
	// 멤버 함수
	int attack();							// 데미지 리턴
	void be_attacked(int damage_earn);				// 입는 데미지
	void move(int x, int y);					// 새로운 위치
	

	void show_stat();						// 상태 
};

// 여기서부터 객체 변수(인스턴스 변수)
Marine::Marine() {  							// Marine 클래스의 객체 생성
	// 디폴트 생성자 초기화
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
}

Marine::Marine(int x, int y) {
	// 사용자 정의 생성자 초기화
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
}

int Marine::attack() {
	return damage;
}

void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) {
		is_dead = true;
	}
}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

void Marine::show_stat() {
	cout << " *** Marine *** " << '\n';
	cout << " Location: ( " << coord_x << " , " << coord_y << " ) " << '\n';
	cout << " HP : " << hp << '\n';
}

int main() {
	Marine* marines[100];

	marines[0] = new Marine(2, 3);  // new와 malloc의 차이: new는 생성자도 만들어줌
	marines[1] = new Marine(3, 5);

	marines[0]->show_stat();
	marines[1]->show_stat();

	cout << "마린 1이 마린 2 공격" << '\n';

	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_stat();
	marines[1]->show_stat();

	// 동적 메모리 해제
	delete marines[0];
	delete marines[1];


}
