/// concept ½Ç½À 2
///
/// 2024-01-11

#include <iostream>
#include <type_traits>

////////////////////////////////////////////////////////////////////////////////
template <typename T1, typename T2,
          typename = std::enable_if_t<std::is_convertible_v<T1, int> &&
                                      std::is_convertible_v<T2, int>>>
long long add_int(T1 t1, T2 t2) {
  return {t1 + t2};
}

////////////////////////////////////////////////////////////////////////////////
#include <concepts>

template <typename T>
concept ConvertInt = std::is_convertible_v<T, int>;

template <ConvertInt T1, ConvertInt T2> long long add_int(T1 t1, T2 t2) {
  return {t1 + t2};
}

int main() {
  std::cout << add_int(1, 1) << std::endl;
  return 0;
}