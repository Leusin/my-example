/// 직접 만들어본 is_array 함수
///
/// 2024-01-11

#include <iostream>

template <typename T> struct is_array_custom {
  static constexpr bool value = false;
  static constexpr size_t size = -1;
};

template <typename T, size_t N> struct is_array_custom<T[N]> {
  static constexpr bool value = true;
  static constexpr size_t size = N;
};

template <typename T> void foo(T &a) {
  if (is_array_custom<T>::value) {
    std::cout << "size of array : " << is_array_custom<T>::size << std::endl;
  }
}

int main() {
  int x[3] = {1, 2, 3};

  foo(x);

  return 0;
}