#include<bits/stdc++.h>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    auto stop = lower_bound(stops.begin(),stops.end(),tank);
    auto end = stops.back();
    int refils = 1, stop_v = *stop;

    while(stop_v != end || (stop_v + tank) < dist)
    {
        stop = lower_bound(stops.begin(),stops.end(),tank+stop_v);
        stop_v = *stop;
        refils++;
    }

    return refils;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    bool no = false;
    
    vector<int> stops(n);
    cin >> stops[0];
    for (int i = 1; i < n; i++){
        cin >> stops.at(i);
        no = (stops[i] - stops[i-1]) > m ? true : false;
    }
    no = (d - stops.back()) > m ? true: no;
    cout << (no ? -1 : compute_min_refills(d, m, stops)) << "\n";

    return 0;
}
