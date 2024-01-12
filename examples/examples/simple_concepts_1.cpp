/// concept ½Ç½À 1
///
/// 2024-01-11

#include <concepts>
#include <iostream>

template <typename T>
concept GT4 = sizeof(T) >= 4;

template <typename T>
  requires GT4<T>
void foo(T a) {}

int main() {
  foo(short()); // error
  foo(int());
  foo(long());

  return 0;
}