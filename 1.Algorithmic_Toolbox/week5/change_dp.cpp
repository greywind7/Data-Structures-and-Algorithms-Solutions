#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> arr(1001,-1);


int get_change(int m) {
  return arr[m];
}

int mini(int x)
{
  if(x == 0)
    return 0;
  if(x == 1 || x == 3 || x == 4)
    return 1;
  if(x < 0)
    return 1001;
  else
    return min(min(1+get_change(x-1),1+get_change(x-3)),1+get_change(x-4));

}

int main() {
  arr[0] = 0;
arr[2] = 2;
  int m;
  for(int i =1; i <= 1000; i++)
  {
    arr[i] = mini(i);
  }
  arr[0] = 0;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
