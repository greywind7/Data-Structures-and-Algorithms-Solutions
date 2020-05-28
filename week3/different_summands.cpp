#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int cur = 1, nxt = 2;

  while (n!= 0)
  {
    if(cur + nxt <= n)
    {
      summands.push_back(cur);
      n -= cur;
    }
    else
    {
      summands.push_back(n);
      n = 0;
    }
    cur++;
    nxt++;
  }
  
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
