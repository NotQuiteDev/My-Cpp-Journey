#include <iostream>

int main() {
    int gold = 100; // 우리집 금고에 100원 있음
    int* ptr = &gold; // ptr이라는 메모지에 금고 주소를 적음

    std::cout << "금고 내용물: " << gold << "\n";
    std::cout << "금고 주소(&gold): " << &gold << "\n";
    std::cout << "메모지에 적힌 주소(ptr): " << ptr << "\n";

    //진짜 중요한 역참조
    *ptr = 500; // 메모지에 적힌 주소로 가서 내용물을 500으로 바꿔버림

    std::cout << "조작 후 금고 내용물: " << gold << " (해킹완료!)\n";

    return 0;

}