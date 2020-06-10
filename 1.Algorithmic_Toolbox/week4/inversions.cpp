#include<bits/stdc++.h>

using namespace std;

long long get_number_of_inversions(vector<int> &a) {
  long long number_of_inversions = 0;
  for(int i = 0; i < a.size()-1;i++)
    for(int j = i + 1; j < a.size(); j++)
      if(a[i] > a[j])
        number_of_inversions++;
  return number_of_inversions;
}

int merge_inver(vector<int>&X, int l, int r)
{
    if(l == r) return 0;
    // cout << "ONE" << endl;

    int m = (l+r)/2;
    long li = merge_inver(X,l,m), ri = merge_inver(X,m+1,r),inv = li + ri;
    vector<int> temp;
    int i = l, j = m + 1;

    while(i < m+1 || j < r+1)
    {
        // cout << "TWO" << endl;
        if(i <= m && j <= r)
        {
            if(X[i] > X[j])
            {
              // cout << "THREE" << endl;
              inv += m - i + 1;
              temp.push_back(X[j++]);
            }
            else 
                temp.push_back(X[i++]);
        }
        else if (i <= m && j > r)
        {
            // cout << "FOUR" << endl;
            while(i <= m)
                temp.push_back(X[i++]);
            i++;
        }
        else if(i > m && j <= r)
        {
            // cout << "FIVE" << endl;
            while(j <= r)
                temp.push_back(X[j++]);
            j++;
        }
    }

    auto ti = temp.begin();
    while(l <= r && ti != temp.end())
    {
      // cout << "SIX" << endl;
      X[l] = *ti;
      l++;
      ti++;
    }
    temp.clear();
    return inv;
}

void stress()
{
  int range = rand() % 10 + 3;
  vector<int> x(range);
  while(range--) x[range] = rand() % 10;
  cout << x.size() << endl;
  for(int i:x) cout << i << ' ';
  long nv = get_number_of_inversions(x), qk = merge_inver(x,0,x.size()-1);
  bool res = (nv == qk);
  // for(int i:x) cout << i << ' ' << endl << res;
  if(res){
    // cout << x.size() << endl;
    // for(int i:x) cout << i << ' ';
    cout << '\n' << nv << ' ' << qk << "\n\n";
    stress();
  } 
  else
  {
    // cout << x.size() << endl;
    // for(int i:x) cout << i << ' ';
    cout << '\n' << nv << ' ' << qk << endl; 
  }
  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << merge_inver(a,0,a.size()-1) << '\n';
  // for(int i:a)
  //   cout << i << ' ';
  // stress();
}
