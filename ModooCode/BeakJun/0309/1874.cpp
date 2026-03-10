#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;
    stack<int> s;
    int x;
    vector<char> ans;

    int cnt = 1;
    
    //cout << "첫번째 x 입력 :";
    
    cin >> x;
    int pop_cnt= 1;
    
    while(pop_cnt != n+1){
        if(s.empty()){
            //비어있으니까 push를 해야하는데 목표인 x보다 크면? NO출력
            if(x < cnt ){
                cout << "NO";
                break;
            }
            else {
                //cout << "x를 푸시 하고, + push cnt :" << cnt << "에서 1더함 \n";
                s.push(cnt);
                ans.push_back('+');
                cnt++;
                
            }
        }
        // 안비어있다면?
        else if(s.top()==x){//pop을 해야할때 == top이 목표숫자와 같을때
            //cout << "pop할때가 됐군" << "\n";
            s.pop();
            ans.push_back('-');
            if(pop_cnt != n)cin >> x;
            pop_cnt++;
        }
        else if(x < cnt){
            cout << "NO";
            break;
        }
        else {
            //cout << "x를 푸시 하고, + push cnt :" << cnt << "에서 1더함 \n";
            s.push(cnt);
            ans.push_back('+');
            cnt++;
        }
        //push해야할때, 그이외(s.가 채워져 있거나, !empty top이 목표숫자가 아닐때 )
        //그것들도 아니라면 NO
    }

    //

    //cout << ans.size();
    if (pop_cnt == n+1) {

        for(int i =0 ; i<ans.size(); i++){
            cout << ans[i] <<"\n";
        }
    }
    


    return 0;
}