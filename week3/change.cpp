#include <iostream>

int get_change(int m) {
  int total = 0;
  total += m/10; m %= 10;
  total += m/5;  m %= 5;
  total += m;
  return total;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
