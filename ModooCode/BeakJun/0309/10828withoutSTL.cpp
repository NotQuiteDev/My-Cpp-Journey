#include <iostream>
#include <string>

using namespace std;

int main() {


    ios::sync_with_stdio(0);
    cin.tie(0);

    const int MX = 1000005;
    int dat[MX];
    int pos = 0;


    int n;
    cin >> n;
    
    
    
    for (int i=0; i<n; i++) {

    
        string cmd;
        cin >> cmd;





        if(cmd == "push"){
            int x;
            cin >> x;
            dat[pos++] = x; 
        }
        else if(cmd == "pop") {
            if(pos == 0) cout << -1<< "\n";
            else cout << dat[--pos] << "\n";
            }
        else if(cmd == "size") cout << pos << "\n";
        else if(cmd == "empty") {
            if(pos == 0) cout << 1<< "\n";
            else cout << 0 << "\n";
        }
        else if(cmd == "top") {
            if(pos == 0) cout << -1<< "\n";
            else cout << dat[pos-1] << "\n";
        }
    }
    

    return 0;
}
