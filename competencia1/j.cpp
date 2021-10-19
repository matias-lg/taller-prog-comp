#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
int main() {
  ll n, k, t;
  vector<ll> v;
  cin >> n;
  cin >> k;
  cin >> t;
  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  // calcular costo normal de la ciudad i
  ll tmp;
  ll cn = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (i == n - 2) {
      cn += v[n - 1] - v[n - 2];
      tmp = cn;
    } else {
      cn += tmp + v[i + 1] - v[i];
      tmp = cn;
    }
  }
  ll dp[n];
  // dp costo con teleport en cada pos
  // indice sera i, destino min(n,i+k)
  for (int tp = 0; tp < n; tp++) {
    ll dest = min(n, tp + k);
    ll r = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (j < tp) {
          // avanzar normal
          r += v[i + 1] - v[i];
        }
        // ver si tpearse
        if (j == tp) {
        }
      }
    }
  }
  return 0;
}