/// 약식 함수 템플릿
///
/// 2024-01-11

#include <concepts>
#include <iostream>

void print(auto n) 
{
	std::cout << "non integral : " << n << std::endl;
}


void print(std::integral auto n) 
{
        std::cout << "integral : " << n << std::endl;
}

int main() 
{
  std::cout << std::boolalpha;

  print(true);
  print('o');
  print(7);
  print(2.0);
  print("abc");
}