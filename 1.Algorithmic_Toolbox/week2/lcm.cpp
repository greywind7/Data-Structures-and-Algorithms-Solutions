#include <iostream>
using namespace std;
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
int gcd_fast(int a, int b)
{
  if(a == 0 || b == 0)
    return max(a,b);
  else 
    return gcd_fast(min(a,b),max(a,b)%min(a,b));
}

long long lcm_fast(int a, int b){
  return (long long) ((long long)(a/gcd_fast(a,b))*b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
