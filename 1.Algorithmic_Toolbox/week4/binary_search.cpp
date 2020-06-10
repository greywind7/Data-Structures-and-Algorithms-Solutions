#include <bits/stdc++.h>

using namespace std;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size() -1; 
  //write your code here

  if(a[left] == x) return 0;
  if(a[right] == x) return right;

  int mid = (left + right)/2, prev_mid = -1;

  while(mid != prev_mid)
  {
    // cout << mid << ' ' << left << ' ' << right << endl;
    if(a[mid] == x) return mid;
    else if(a[mid] < x) left = mid + 1;
    else right = mid;
    prev_mid = mid;
    mid = (left + right)/2;
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

void stress()
{
  int range = rand() % 100;
  vector<int> x(range);
  while(range--) x[range] = rand() % 100;
  // for(int i:x) cout << i << ' ';
  sort(x.begin(),x.end());
  int check = rand() % 100;
  bool res = (linear_search(x, check) == binary_search(x,check));
  // for(int i:x) cout << i << ' ' << endl << res;
  if(res){
    for(int i:x) cout << i << ' ';
    cout << '\n' << linear_search(x, check) << ' ' << binary_search(x, check) << endl;
    stress();
  } 
  else
  {
    for(int i:x) cout << i << ' ';
    cout << '\n' << linear_search(x, check) << ' ' << binary_search(x, check) << endl; 
  }
  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    cout << binary_search(a, b[i]) << ' ';
  }
  // stress();
}
