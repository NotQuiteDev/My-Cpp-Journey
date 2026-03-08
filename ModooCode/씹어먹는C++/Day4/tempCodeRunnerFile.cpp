#include <iostream>

class MyString {
  private:
    char* content;
    int len;
    

  public:
    MyString(char c);
    MyString(const char* str);
    void StrLength();
    ~MyString();
};

MyString::MyString(char c) {
    len = 1;
    content = new char[2];
    content[0] = c;
    content[1] = '\0';
}
MyString::MyString(const char* str){
    len = 2;
    while(100000000){
        if(*(str+len) == '\0'){
            std::cout<<"이 문자열의 길이 : " << len << std::endl;
            return;
        }
        len++;
    }
    

}

void MyString::StrLength() {
    std::cout << "Str의 길이 : " << len << std::endl; 
}

MyString::~MyString(){
    std::cout << "소멸생성자 실행됨" << std::endl;
    delete[] content;

}

int main() { 
    MyString a('c');
    MyString b("hello");
    a.StrLength();
    b.StrLength();

    return 0;
}