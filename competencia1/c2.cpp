#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define ll long long

using namespace std;
ll m = 1000000007;

void print(vector<vector<ll>> &f, int n, int k) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cout << "(" << f[i][j] << ")";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  ll n, t;

  cin >> n >> t;
  vector<ll> puestos(n);
  for (int i = 0; i < n; i++) {
    ll p;
    cin >> p;
    puestos[i] = p;
  }

  vector<vector<ll>> f(t + 1, vector<ll>(t + 1, 0));
  for (int i = 1; i < t; i++) {
    ll k = (i - 1) % n;
    for (int j = 1; j < t; j++) {
      if (j - puestos[k] < 0) {
        f[i][j] = f[i - 1][j];
      } else {
        f[i][j] = 1 + f[i - 1][j - puestos[k]];
      }
    }
  }
  // print(f,t,t);
  cout << f[t - 1][t - 1] + 1 << endl;
  // cout << *max_element(f.begin(), f.end())+1 << endl;
}
