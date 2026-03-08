#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);


    std::vector<int> v;

    for (int i =0; i<9 ; i++) {
        int x;
        std::cin >> x;
        v.push_back(x);
    }
    std::vector<int> copy;

    for (int i=0; i < 9 ; i++){
        copy.push_back(v[i]);
    }

    std::sort(copy.begin(), copy.end());
    std::cout << copy[8] <<"\n";
    for (int i=0; i<9 ;i++){
        if(copy[8] == v[i]){
            std::cout << i+1 << "\n";
            return 0;
        }
    }



    return 0;
}