#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
int main() {
  ll res = 0;
  int n, m;
  cin >> n >> m;
  ll dp[n][m];
  string v[n];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v[i] = s;
  }
  for (int i = 0; i < n; i++) {
    ll gs = 0;
    ll bs = 0;
    for (int k = 0; k < m; k++) {
      if (v[i][k] == 'G') {
        gs++;
      } else {
        bs++;
      }
    }
    res += max(bs, gs);
  }
  cout << res;

  return 0;
}