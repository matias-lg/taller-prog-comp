#include <bits/stdc++.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int xr[5002][5002];
int dp[5002][5002];

int main() {
  ll n, m, k, q, l, r;
  // int xr[N][N];
  // int dp[N][N];
  cin >> n;
  vector<ll> a;
  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  cin >> q;
  // ll xr[n][n];
  for (int i = n - 1; i >= 0; i--) {
    xr[i][i] = a[i];
    for (int j = i + 1; j < n; j++) {
      xr[i][j] = xr[i + 1][j] xor xr[i][j - 1];
    }
  }
  // ll dp[n][n];
  for (int i = n - 1; i >= 0; i--) {
    dp[i][i] = xr[i][i];
    for (int j = i + 1; j < n; j++) {
      dp[i][j] = max({xr[i][j], dp[i][j - 1], dp[i + 1][j]});
    }
  }
  // cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> l;
    cin >> r;
    cout << dp[l - 1][r - 1] << endl;
  }

  return 0;
}
