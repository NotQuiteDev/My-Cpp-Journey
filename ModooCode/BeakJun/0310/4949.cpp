#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    line ='0';
    stack<char> s;
    while(line !="."){
        getline(cin,line);
        for(int i=0; i<line.size();i++){
            //(이거나 [이게 나오면 스택에 넣는다.근데 닫는게 나왔을때, 스택의 top과 짝이 안맞으면 NO
            //짝이 맞는게 나오면 스택 지우고 다음, 온점을 만났을때, 스택이 비어있으면 YES
            //cout << "확인된 글자 : " << line[i];
            if(line[i] == '(' || line[i] == '['){
                s.push(line[i]);//괄호가 나오면 집어넣기
            }
            else if(line[i] == ')'){//맨위가 짝이아니면 틀린거
                if (s.empty()||s.top() != '(') {
                    cout << "no" <<"\n" ;
                    break;
                }
                else if(s.empty()||s.top() == '('){
                    s.pop();
                }
            }
            else if(line[i] == ']'){
                if (s.empty()||s.top() != '[') {
                    cout << "no" <<"\n";
                    break;
                }
                else if(s.empty()||s.top() == '['){
                    s.pop();
                }
            }
            else if(line[i] == '.'){
                if(s.empty()) {
                    if(i!=0)cout << "yes" <<"\n";
                    else break;
                    break;
                }
                else {
                    cout << "no" <<"\n";
                break;}

            }

        }
        while(!s.empty()) s.pop();
    }

    return 0;
}