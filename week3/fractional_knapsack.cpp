#include <bits/stdc++.h>

using namespace std;
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  map <double,int> worth;
  int tot_wt = 0;
  tot_wt+= accumulate(weights.begin(),weights.end(),tot_wt);
  
  if(tot_wt <= capacity)  
    return accumulate(values.begin(),values.end(),0);

  for (int i = 0; i < values.size( ); i++)
    worth[(double) -1 * values[i]/weights[i] ] = i;

  auto ptr = worth.begin();
  while (capacity != 0)
  {
    int indx = ptr->second;
    // cout << ptr->first << " " << weights[indx] << endl;
    if(capacity > weights[indx])
    {
      value += (double) -1 * ptr->first * weights[indx];
      capacity -= weights[indx];
    }
    else
    {
      value += (double) -1 *  ptr->first * capacity;
      capacity = 0;
    }
    ptr++;
  }
  

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  printf("%.4f\n",optimal_value);
  return 0;
}
