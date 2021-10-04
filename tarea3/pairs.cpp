#include <bits/stdc++.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
int n, m, k;
int main() {
  cin >> n >> m >> k;
  int p[n];
  ll c[n];
  ll dp[n][k + 1];
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    p[i] = tmp;
  }
  c[0] = p[0];
  for (int i = 1; i < n; i++) {
    c[i] = c[i - 1] + p[i];
  }
  // solucion del problema hasta el indice i con j grupos
  // i, 0 0 hasta m-1 donde vale c[i-1]
  // j, desde 0 a k-1
  // con j > i, se tienen mas grupos que elementos hay -> 0
  // dp[i][j] = max((dp[i - m + 1][j - 1] + c[i] - c[i - m + 1]), dp[i - 1][j]);
  // dp[m - 1][1] = c[m - 1];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k + 1; j++) {
      if (i < j - 1 or i < m - 1 or j == 0) {
        dp[i][j] = 0;
        // cout << i << " " << j << " " << dp[i][j] << endl;
        continue;
      }
      if (i == (m - 1) and j == 1) {
        dp[i][j] = c[m - 1];
        // cout << i << " " << j << " " << dp[i][j] << endl;
        continue;
      }
      // dp[2][1] = max(dp[1][0]+c[2]-c[1]=3, )
      int fix = max(0, i - m);
      dp[i][j] = max((dp[fix][j - 1] + c[i] - c[fix]), dp[i - 1][j]);
      // cout << i << " " << j << " " << dp[i][j] << endl;
    }
  }

  cout << dp[n - 1][k];

  return 0;
}