#include <iostream>

int main(){
    int n;
    int sum=0;
    std::cin >>n ;
    for(int i=1; i<=n ; i++){
        if(i% 3 == 0 || i%5 == 0){
            sum += i;
            //std::cout << i << "\n";
        }
    }
    std::cout << sum << "\n";

}