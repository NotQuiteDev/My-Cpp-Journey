#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> L;
    
    //이제 해야할것 한줄을 입력해서 L에 집어넣기 하나하나

    string s;
    cin >> s;

    //cout << s;

    //이제 받은 S를 리스트에 집어넣기
    for(int i =0; i<s.size(); i++){
        L.push_back(s[i]);
    }
    auto t= L.end();
    int M;
    cin >> M;

    char input;

    for(int i = 0 ; i < M ; i++){
        cin >> input;

        if(input == 'L') {
            //cout << "L을 입력 받음";//L일때 처리
            if( t!= L.begin())t--;
        }

        else if(input == 'D'){
        //cout << "D를 입력 받음"; //D일때 처리
        if(t!= L.end()) t++;
        }    

        else if(input == 'B'){
            
            //cout << "B를 입력받음 "; //B일때 처리 커서 왼쪽의 문자를 삭제함
            if(t != L.begin()) {
                t = L.erase(--t);
            }
        }    
        else if(input == 'P'){
            //cout << "P를 입력받음"; //P일때 처리
            char temp;
            cin >> temp;
            L.insert(t,temp);
        }
            
    }

    for(auto i:L){
        cout << i;
    }


    //M에 따라 줄 입력 받고 명령 수행하기
    

    return 0;
}