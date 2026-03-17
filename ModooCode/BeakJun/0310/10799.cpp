#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //스택으로 받는다.
    //현재 늘어선 철근수 = stack.size()
    //레이저 나왔을때, pop한뒤 size를 더해줘서 더해진 철근수를 구한다.
    //그리고 철근이 끝날때는 철근수 하나를 더해줘야함
    stack<char> s;

    int cnt=0;
    char before =0;
    string str;
    cin >> str;
    for(auto c : str){

        if (c == '(') {
            s.push(c);
            //cout << "push\n";
        }
        else if (c==')'){
            if(before=='('){ //레이저를 만났음
                //레이저일때는 현재 스택에서 하나 지우고, 스택에 남아있는 괄호수 만큼 cnt를 더해줌
                s.pop();
                cnt += s.size();
                //cout << "laser: +"<<s.size()<< "\n";
            }
            else {//레이저를 안만남
                //철근이 끝나는 거면 1을 더해주고 stack에 하나를 빼준다.
                s.pop();
                cnt++;
                //cout << "iron bar end +1"<<"cnt = "<< cnt << "\n";
            }
        }
        before = c;
    }   
    cout << cnt <<"\n";


    return 0;
}