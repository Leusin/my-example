/// 2024-01-12

//
// 람다는 세 개의 구조로 이루어져 있다.
//
// [/*캡쳐*/] -> void /*반환 값*/ (/*입력값*/) { /*본문*/ };
// [/*캡쳐*/] (/*입력값*/) { /*본문*/ };
// [/*캡쳐*/] { /*본문*/ };
//

#include <algorithm>
#include <iostream>
#include <vector>

int main() 
{
 // 람다 사용법

 // 1. auto 변수로 보관해서 사용
  auto fn1 = []() { std::cout << "Hey" << std::endl; };

  fn1; // 아무일도 안 일어난다.
  fn1(); // 함수 호출

  // 2. 바로 사용
  []() { std::cout << "Wow\n"; }(); // 뒤에 () 달아서 함수 호출

  return 0;
}