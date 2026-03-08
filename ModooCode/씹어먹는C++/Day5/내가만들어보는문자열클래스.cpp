#include <iostream>

class MyString {
  private:
    char* content;
    int len;
    

  public:
    MyString(char c);
    MyString(const char* str);
    void StrLength();
    void AddStr(const MyString& addingString);
    void PrintStr();
    int FindStr(const MyString& string);
    int SameStr(const MyString& string);
    void CompareStr(const MyString& string);
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


int MyString::FindStr(const MyString& string){
    //myString의 len을 먼저 검사해서 포함될 수 있는지 볼까?
    //그냥 첫글자를 일단 찾는데, 찾는범위만 제한하면 ㄱㅊ을듯
    int exist = -1;
    for (int i = 0; i<len-(string.len-1) ; i++){

        std::cout << content[i] <<" : content[i] |||| string.content[0] :" << string.content[0] << std::endl;
        if( content[i]==string.content[0]){
            for(int k=0; k<string.len; k++){
                if (content[i+k] != string.content[k]) {
                    std::cout << content[i+k] << "와" <<string.content[k] << "가 다르군요" << std::endl;
                    break;
                }
                std::cout << "여기까진왔네요1  k,stringlen = "<< k << " , " << string.len <<std::endl;
                if (k == string.len-1) {
                    
                    exist = i+1;
                }
            }
        }
        if(exist!= -1) break;
    }
    if(exist!= -1) std::cout << "해당 단어를"<< exist << " 번째 부터 포함하고있네요" << std::endl;
    else std::cout << "해당 단어가 없어요" << std::endl;
    return exist;

}

void MyString::StrLength() {
    std::cout << "Str의 길이 : " << len << std::endl; 
}

int MyString::SameStr(const MyString& string) { 
    if(len != string.len) {
        std::cout <<"문자열 길이가 다르므로 다른 문자열임" << std::endl;
        return 0;
    }
    for(int i=0 ; i < len ; i++){
        if(content[i]!=string.content[i]) {
            std::cout <<"문자가 다르므로 다른 문자열임" << std::endl;
            return 0;
        }
    }
    std::cout <<"축하합니다. 같은 문자열이네요!" << std::endl;
    return 1;

}
void MyString::CompareStr(const MyString& string){
    //둘이 완전히 같다면?
    if (this->SameStr(string) ==1) {
        std::cout << "크기비교해볼것도없고 얘네 둘은 같습니다," << std::endl;
        return;
    }

    int length = len;
    if(len<string.len) length = string.len; 

    for (int i = 0 ; i<length; i++){
        if (content[i] ==string.content[i]){
            continue; //둘이 같으면 다음거 비교
        }
        //둘이 다르면 바로 크기 비교해서 바로 출력하면됨
        std::cout << "크기 비교 : " << (content[i] < string.content[i] ? content : string.content) << std::endl;
        return;
    }
}

MyString::~MyString(){
    std::cout << "소멸생성자 실행됨" << std::endl;
    delete[] content;

}
void MyString::AddStr(const MyString& addingString){

    //현재 생성자의 content길이에 addingString.len을 더해서 길이를 맞춰야함
    char *newString = new char[len+addingString.len+1 ]; // '\0'포함


    //0부터 len까지 기존 것 채우고, 그다음부터 addingString의 content를 채우기

    for(int i=0; i<len ; i++){
        newString[i] = content[i];
    }

    for(int i=0; i<=addingString.len ; i++){ // '\0'포함한 구역
        newString[i+len] = addingString.content[i];
    }
    int newlen = len + addingString.len;
    len = newlen;
    delete[] content;
    content = newString;
    
}
void MyString::PrintStr(){
    std::cout << "스트링 프린트 : " << content << std::endl;
}
int main() { 
    MyString a("abcde");
    MyString b("abcdef");

    b.CompareStr(a);
    
    return 0;
}