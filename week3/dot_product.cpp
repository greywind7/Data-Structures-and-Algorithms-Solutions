#include<bits/stdc++.h>

using namespace std;
using prq = priority_queue<int>;

long long max_dot_product(prq a, prq b) {
  // write your code here
  long long result = 0;
  while(!a.empty()) {
    result += (long long) (a.top() * b.top());
    a.pop();
    b.pop();
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  prq a, b;
  for (size_t i = 0; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    a.push(tmp);
  }
  for (size_t i = 0; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    b.push(tmp);
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
