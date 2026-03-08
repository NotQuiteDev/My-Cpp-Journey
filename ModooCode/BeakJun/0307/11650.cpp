#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    //내 생각에 일단 x좌표에 따른 vector들을 만든다음 걔네를 소트 하는게 편할거같은데

    //근데 구현은 어려워도 (x,y) 벡터로 저장하는게 훨씬 나을거같긴하다. 
    //(x,y)로 받으면 일단 다 입력받고, x에 대해서 y로 정렬

    //일단 비싸긴해도, 계속 돌면서 해야할듯

    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }


    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }





    return 0;
}