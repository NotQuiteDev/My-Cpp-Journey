#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    //std:: cout << n<< std::endl;


    std::vector<int> v;

    for(int i = 0; i< n; i++){
        int x;
        std::cin >> x;
        v.push_back(x);

    }

    sort(v.begin(), v.end());



    std::cout << v[0] << " " << v[v.size()-1] << "\n";
}