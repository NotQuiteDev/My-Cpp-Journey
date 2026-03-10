#include <iostream>
#include <utility>

using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x){
    dat[tail++] = x;
}

void pop(){
    cout << dat[head++] <<"\n";
}

int front(){
    cout << dat[head] <<"\n";
}

int back(){
    cout << dat[tail-1] << "\n";
}

void test(){
  push(10); push(20); push(30);
  cout << front() << '\n'; // 10
  cout << back() << '\n'; // 30
  pop(); pop();
  push(15); push(25);
  cout << front() << '\n'; // 30
  cout << back() << '\n'; // 25
}

int main(void) {
  test();  

  return 0;
}