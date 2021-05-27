#include<bits/stdc++.h>

using namespace std;

int getHeight(int node, vector< queue<int> >&tree)
{
  if(tree[node].empty())
    return 1;
  else{
    // cout << "WEEEE\n";
    int height = INT_MIN;
    queue<int>temp = tree[node];
    while(!temp.empty()){
      height = max(height,getHeight(temp.front(),tree));
      temp.pop();
    }
    return height + 1;
  }
}

int getHeightBFS(int node, vector< queue<int> >&tree)
{
  int height = 1;
  queue<int>temp = tree[node];
  while(!temp.empty())
  {
    height++;
    int siz = temp.size();
    while(siz--){
      queue<int>temp2 = tree[temp.front()];
      while(!temp2.empty())
      {
        temp.push(temp2.front());
        temp2.pop();
      }
      temp.pop();
    }
  }
  return height;
}

int main()
{
  int n, root;
  cin >> n;
  vector< queue<int> >tree(110000);
  for(int i=0;i<n;i++)
  {
    int x;
    cin >> x;
    if(x == -1)
      root = i;
    else
      tree[x].push(i);
  }
  cout << getHeightBFS(root,tree) << endl;
}