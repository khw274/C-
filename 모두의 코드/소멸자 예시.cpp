// 소멸자 호출 확인하기
#include <string.h>
#include <iostream>
class Test {
	char c;				// 멤버 변수
public:
	Test(char _c) {		// 멤버 함수, 생성자
		c = _c;
		std::cout << "생성자호출" << c << std::endl;
	}
	~Test() {			// 소멸자
		std::cout << "소멸자호출" << c << std::endl; 
	}
};

void simple_function() { // 지역 함수
	Test b('b');  // class Test의 객체 b 생성
}

int main() {
	Test a('a');  // class Test의 객체 a 생성

	simple_function();  // 여기서 생성된 객체 b는 지역 객체기 때문에 simple_function()이 종료됨과 동시에 소멸
}
