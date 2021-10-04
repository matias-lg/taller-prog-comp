#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
int n;
bool cond(int nn,int numvacas,vector<long long> stalls) {
  int vacas = 1;
  int s = stalls[0];
  for (int i = 1; i < n; i++){
    if (stalls[i] - s >= nn) {
      s = stalls[i];
      vacas++;
      if (vacas == numvacas) {
        return true;
      }
    }  
    }
  return false;
}

int main() {
  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    cin>>n;
    int c; cin >> c;
    vector<long long> stalls;
    for (int j = 0; j < n; j++) {
      long long x; cin >> x;
      stalls.push_back(x);
    }
    sort(stalls.begin(), stalls.end());
    int m = 0;
    int l = 0;
    int r = stalls[n - 1];
    while (l < r) {
      int mid = (l+(r-l)/2);
      if (cond(mid, c, stalls)) {
        if (mid > m) {
          m = mid;
        }
        l = mid + 1;
      } else {
       r = mid;
      }
    }
    cout << m << endl;
  }

}
