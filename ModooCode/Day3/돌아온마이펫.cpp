#include <iostream>


typedef struct Animal {
    char name[30];
    int age;

    int health;
    int food;
    int clean;
} Animal;

int main() {
    Animal *list[10];
    int animal_num= 0;

    for(;;){
        std::cout << "1. 동물 추가하기" << std::endl;
        std::cout << "2. 놀기 " << std::endl;
        std::cout << "3. 상태 보기 " << std::endl;

        int input;
        std::cin >> input;

        switch(input){

        }
    }
}