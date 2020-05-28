#include<bits/stdc++.h>
using namespace std;

using std::vector;
using std::string;

string largest_number(vector<string> a) {
  //write your code here
  sort(a.begin(),a.end());
  vector<string> re;
  char f = a[0][0];
  stringstream gib;
  for(string i:a)
  {
      if(i[0] == f)
        gib << i;
      else
      {
        string tmp;
        gib >> tmp;
        re.push_back(tmp);
        f = i[0];
        gib.str("");
        gib << i;
      }
  }

  sort(re.rbegin(),re.rend());

  std::stringstream ret;
  for (size_t i = 0; i < re.size(); i++) {
    ret << re[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
