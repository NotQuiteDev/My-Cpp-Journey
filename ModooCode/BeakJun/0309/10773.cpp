#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;

    int input;
    stack<int> S;
    for(int i=0; i<K ; i++){
        cin >> input;
        if(input == 0) S.pop();
        else S.push(input);
    }

    int solution =0;
    while(!S.empty()){
        solution += S.top();
        S.pop();
    }

    cout << solution;



    return 0;
}