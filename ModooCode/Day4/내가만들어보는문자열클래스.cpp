#include <iostream>

class MyString {
  private:
    char* content;
    int len;
    

  public:
    MyString(char c);
    MyString(const char* str);
    void StrLength();
    void AddStr(MyString &myString1, MyString &myString2);
    ~MyString();
};

MyString::MyString(char c) {
    len = 1;
    content = new char[2];
    content[0] = c;
    content[1] = '\0';
}
MyString::MyString(const char* str){
    len = 0;

    while(str[len] != '\0') {
        len++;
    }
    std::cout<<"이 문자열의 길이 : " << len << std::endl;

    content = new char[len+1];
    for (int i=0; i<=len ; i++){
        content[i] =str[i];
    }

    

}

void MyString::StrLength() {
    std::cout << "Str의 길이 : " << len << std::endl; 
}

MyString::~MyString(){
    std::cout << "소멸생성자 실행됨" << std::endl;
    delete[] content;

}
void MyString::AddStr(MyString &myString1, MyString &myString2){
    int len1 = myString1.len;
    int len2 = myString2.len;

    
}

int main() { 
    MyString a('c');
    MyString b("hello");
    a.StrLength();
    b.StrLength();

    return 0;
}