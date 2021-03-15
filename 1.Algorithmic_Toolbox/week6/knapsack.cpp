#include<bits/stdc++.h>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  int n = w.size();
  int mat[n][W+1];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < W+1; j++)
    {
      int wt = w[i];
      if(j - wt < 0){
        if(i==0) mat[i][j] = 0;
        else mat[i][j] = mat[i-1][j];
      }
      else{
        if(i == 0) mat[i][j] = wt;
        else mat[i][j] = max(mat[i-1][j-wt]+wt,mat[i-1][j]);
      }
    }
  }
  // for(int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < W+1; j++)
  //   {
  //     cout << mat[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  return mat[n-1][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  sort(w.begin(),w.end());
  std::cout << optimal_weight(W, w) << '\n';
}
