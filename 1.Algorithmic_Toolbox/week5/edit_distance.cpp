#include<bits/stdc++.h>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here

  int m = str1.length(), n = str2.length();
  int mat[m+1][n+1];

  for(int i = 0; i < m+1; i++)
    mat[0][i] = i;
  for(int i = 0; i < n+1; i++)
    mat[i][0] = i;

  for (int i = 1; i < m+1; i++)
  {
    for (int j = 1; j < n+1; j++)
    {
      int match = mat[i-1][j-1], del = mat[i][j-1] + 1, in = mat[i-1][j] + 1, mis = mat[i-1][j-1] + 1;

      if(str1[i-1] == str2[j-1])
        mat[i][j] = min(min(del,in),match);
      else
        mat[i][j] = min(min(del,in),mis);
    }
    
  }
  // for(int i = 0; i < m+1; i++)
  // {
  //   for (int j = 0; j < n+1; j++)
  //   {
  //     cout << mat[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  return mat[m][n];

}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
