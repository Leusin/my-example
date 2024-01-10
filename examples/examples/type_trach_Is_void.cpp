/// type traits ���ظ� ���� ���� ������ is_void �Լ�
/// 
/// 2024-01-10

#include <iostream>

template<typename T>
bool is_void() { return false; }

template <> 
bool is_void<void>() { return true; }

int main() 
{
  auto isNotVoid = is_void<int>();
  auto isVoid = is_void<void>();

  std::cout << ((isNotVoid) ? "True" : "False") << std::endl;
  std::cout << ((isVoid) ? "True" : "False") << std::endl;
 
  return 0;
}