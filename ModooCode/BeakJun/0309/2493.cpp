#include <iostream>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

int main() {
    vector<int> v;
    stack<pair<int,int>> s;

    int n;
    cin >> n;
    int cnt=1;

    int input;
    for (int i=0; i<n ; i++){
        cin >> input;
        while(true){
            if(s.empty()){
                v.push_back(0);
                s.push({input, cnt++});
                break;
            }
            else{
                //s.top().first와 층 비교

                if(s.top().first > input){//input보다 s.탑 키가 크면  걔를 v에 등록 하고, input을 스택에 넣기
                    v.push_back(s.top().second);
                    s.push({input,cnt++});
                    break;
                }
                else if(s.top().first < input){
                    s.pop();
                }
                //input보다 작으면 걔를 등록하고, 스택에 안넣고 
            }
        }
    }

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }




    return 0;
}