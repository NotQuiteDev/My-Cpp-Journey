#include <iostream>
#include <stack>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans=0;

    stack<int> s;
    string str;
    char last='0';

    cin >> str;
    for(int i=0 ; i<str.size(); i++){
        if(str[i] == '(') {
            s.push(-1);
        }
        else if(str[i] == '['){
            s.push(-2);
        }
        else if(str[i] ==')'){//()이면 2를 스택에 쌓고, 
                            //숫자가 맨위에 있으면 숫자를 tmp에 더하기
                            //(를 만나면 tmp에 2를 곱하고 해당수를 push후 tmp=0 break
            int tmp =0;                //empty이거나,[이거라면 잘못된거니까 바로 0출력하고 리턴
            while(true){
                if( !s.empty() && s.top() > 0){
                    tmp += s.top();
                    s.pop();
                }
                else if(!s.empty() && s.top() == -1){
                    
                    if(last == '('){
                        s.pop(); //-1제거
                        s.push(2);
                        break;
                    }
                    else {
                        tmp*=2;
                        s.pop();
                        s.push(tmp);
                        tmp = 0;
                        break;
                    }
                }
                else if(s.empty() || s.top() == -2){
                    cout << 0<<"\n";
                    return 0;
                }
            }
        }
        else if(str[i] == ']'){

        }

        last = str[i];

    }


    


    return 0;
}