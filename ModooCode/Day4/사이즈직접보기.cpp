#include <iostream>

int main(){
    int Int;
    short Short;
    char Char;
    long Long;
    long long Long_Long;
    float Float;
    double Double;

    std::cout << "char의 크기는     : " << sizeof(Char)      << "Byte" << std::endl;
    std::cout << "short의 크기는    : " << sizeof(Short)     << "Byte" << std::endl;
    std::cout << "int의 크기는      : " << sizeof(Int) << "Byte" << std::endl;
    std::cout << "long의 크기는     : " << sizeof(Long)      << "Byte" << std::endl;
    std::cout << "long long의 크기는: " << sizeof(Long_Long) << "Byte" << std::endl;
    std::cout << "float의 크기는    : " << sizeof(Float)     << "Byte" << std::endl;
    std::cout << "double의 크기는   : " << sizeof(Double)    << "Byte" << std::endl;

    int* ptr_int;
    char* ptr_char;
    double* ptr_double;
    std::cout << "int 포인터 크기   : " << sizeof(ptr_int)    << "Byte" << std::endl;
    std::cout << "char 포인터 크기  : " << sizeof(ptr_char)   << "Byte" << std::endl;
    std::cout << "double 포인터 크기: " << sizeof(ptr_double) << "Byte" << std::endl;
    
    return 0;
}