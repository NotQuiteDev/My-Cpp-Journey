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
    vector<char> ans;
    int target;
    int cur=1;


    for(int i=0; i<n ; i++){
        
        
        cin >> target;
        while(true){
            if(!s.empty() && s.top() == target) {
                //cout << "pop을 함 대상 :" << s.top() << "\n";
                s.pop();
                ans.push_back('-');
                break;
            }
            else if(!s.empty() && target < s.top()){
                cout << "NO";
                return 0;
            }
            else {
                s.push(cur++);
                //cout << "push 함 대상 : " << cur-1 << "\n";
                ans.push_back('+');
            }
        }


    }

    for(int i =0 ; i<ans.size(); i++){
        cout << ans[i] << "\n";
    }


    return 0;
}