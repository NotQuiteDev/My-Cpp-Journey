#include <iostream>

int main() {
    
    int A,B,T;
    char C;

    std::cin >> T;


    for(int i = 0; i<T; i++) {
        std::cin >> A;
        std::cin >> C;
        std::cin >> B;
        std::cout << A+B<<std::endl;
    }
    
    
    return 0;
}