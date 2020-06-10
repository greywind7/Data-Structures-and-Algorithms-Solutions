#include<bits/stdc++.h>

using namespace std;

vector<int> optimal_points(map <int, pair<int, int> > &in_pts) {
  vector<int> points;
  //write your code here
  for (size_t i = 0; i < in_pts.size(); ++i) {
    
    while(in_pts.size()!=0)
    {
      auto cur = in_pts.begin();
      int cur_min = cur->first;
      points.push_back(cur_min);
      for(auto i = in_pts.begin(); i != in_pts.end();)
      {
        if(cur_min >= i->second.first && cur_min <= i->second.second)
          in_pts.erase(i++->first);
        else
          ++i;
      }
    }
    
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  map <int, pair<int, int> > in_pts;
  
  for (int i = 0; i < n; i++)
  {
    int start, end;
    cin >> start >> end;
    in_pts[end] = make_pair(start,end);
  }
  
  vector<int> points = optimal_points(in_pts);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
