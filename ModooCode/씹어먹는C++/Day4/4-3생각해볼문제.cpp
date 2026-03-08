#include <iostream>

class string {
    char *str;
    int len;

    public:
    string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
    string(const char *s);
    string(const string &s);
    ~string();

    void add_string(const string &s);   // str 뒤에 s 를 붙인다.
    void copy_string(const string &s);  // str 에 s 를 복사한다.
    int strlen() {
        for(int i=0; i<100; i++){
            if(*str[i]=='\0'){
                len = i;
                
                break;

            }
            else{continue;}
        }
        return len;
    }                       // 문자열 길이 리턴
};

int main() {


    return 0;
}