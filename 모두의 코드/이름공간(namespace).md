## 이름공간 (Namespace)

- **이름공간(namespace)**: C++에서 이름 충돌을 방지하기 위해 사용됩니다. 여러 라이브러리나 모듈에서 동일한 이름을 사용하는 경우, 이름공간을 통해 이를 구분할 수 있습니다.

- **std 이름공간**: 표준 라이브러리 함수 및 객체가 포함된 기본 이름공간입니다. C++에서 입출력 관련 함수(`std::cout`, `std::cin`)를 사용할 때 주로 사용됩니다.

- **사용 방법**
  - 전체 이름공간을 사용하는 방법:
    ```cpp
    #include <iostream>

    int main() {
        std::cout << "Hello, World!" << std::endl;
        return 0;
    }
    ```
  - 특정 이름공간을 생략하는 방법 (`using` 키워드 사용):
    ```cpp
    #include <iostream>

    using namespace std;

    int main() {
        cout << "Hello, World!" << endl;
        return 0;
    }
    ```
  - 특정 이름공간의 일부만 사용하는 방법:
    ```cpp
    #include <iostream>

    using std::cout;
    using std::endl;

    int main() {
        cout << "Hello, World!" << endl;
        return 0;
    }
    ```

- **주의사항**: `using namespace std;`는 편리하지만, 코드가 커질 경우 이름 충돌이 발생할 수 있으므로, 필요한 부분에서만 사용하는 것이 좋습니다.
