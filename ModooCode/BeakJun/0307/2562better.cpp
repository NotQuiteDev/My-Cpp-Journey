#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);


    std::vector<int> v;
    int max=0;
    int max_num;

    for (int i =0; i<9 ; i++) {
        int x;
        std::cin >> x;
        v.push_back(x);
        if(max < x) {
            max = x;
            max_num = i+1;
        }
    }

    std::cout<<max <<"\n" <<max_num << "\n";





    return 0;
}