#include <bits/stdc++.h>

using namespace std;

int get_majority_element(vector<int> &a) {
  //write your code here
  unordered_map<int,int> freq;
  for(int i:a) freq[i]++;
  int mj = a.size()/2;
  for(auto j:freq) if(j.second > mj) return 1;
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a) << '\n';
}
