#include <iostream>

int main() {
    int* ptr;
    char* cptr;

    std::cout << "int 포인터 크기 : " << sizeof(ptr) << " 바이트\n";
    std::cout << "char 포인터 크기 :" << sizeof(cptr) << " 바이트\n";

    return 0;
}