#include<bits/stdc++.h>

using namespace std;

int lower_int(vector<int>&x,int val)
{
    int tmp = x[0],i;
    for(i = 0;i < x.size()-1;i++)
        if(val >= x[i] && val < x[i+1]) return x[i];
    return x[i];
}

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    auto stop = lower_int(stops,tank);
    auto end = stops.back();
    // cout << stop << endl;
    if(stop == end) return 0;
    int refils = 1, stop_v = stop;

    while(stop_v != end && (stop_v + tank) < dist)
    {
        stop = lower_int(stops,tank+stop_v);
        stop_v = stop;
        // cout << stop_v << endl;
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
        no = (stops[i] - stops[i-1]) > m ? true : no;
    }
    no = (d - stops.back()) > m ? true: no;
    cout << (no ? -1 : compute_min_refills(d, m, stops)) << "\n";

    return 0;
}
