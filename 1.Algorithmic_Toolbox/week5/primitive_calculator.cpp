#include<bits/stdc++.h>
using namespace std;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

class node{
  public:
  int val, wt;
  class node *prev;
  node(){
    val = 0; wt = 0; prev = nullptr;
  }
};

class node nums[1000001];

void comp(int x)
{
  nums[x].val = x;
  int un = nums[x-1].wt,dos = 1000000,tres = 1000000;
  if(x%2 == 0) dos = nums[x/2].wt;
  if(x%3 == 0) dos = nums[x/3].wt;

  int w = min(min(un,dos),tres);
  nums[x].wt = w + 1;

  if(x%3 == 0){
    if(w == nums[x/3].wt)
      nums[x].prev = &nums[x/3];
  }
  else if(x%2 == 0){
    if(w == nums[x/2].wt)
      nums[x].prev = &nums[x/2];
  }
  else if(w == nums[x-1].wt)
    nums[x].prev = &nums[x-1];


}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  // std::cout << sequence.size() - 1 << std::endl;

  // nums[0].val = 0; nums[0].wt = 0; nums[0].prev = nullptr;
  nums[1].val = 1; nums[1].wt = 0; nums[1].prev = nullptr;
  nums[2].val = 2; nums[2].wt = 1; nums[2].prev = &nums[1];
  nums[3].val = 3; nums[3].wt = 1; nums[3].prev = &nums[1];

  for(int i = 4; i <= 1000000; i++)
    comp(i);
  nums[10].prev = &nums[9];
  // cout << nums[10].prev->val << endl;
  stack<int>X;

  class node* tp = &nums[n];

  while(tp!=nullptr)
  {
    X.push(tp->val);
    tp = tp->prev;
  }
  cout << nums[n].wt << endl;
  while(!X.empty())
  {
    cout << X.top() << ' ';
    X.pop();
  }
  cout << endl;



  // for (size_t i = 0; i < sequence.size(); ++i) {
  //   std::cout << sequence[i] << " ";
  // }
}
