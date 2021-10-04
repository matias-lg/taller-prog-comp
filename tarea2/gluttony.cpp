#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>
using ll = long long;
using namespace std;

int n;
ll k;
vector<ll> a;
vector<ll> f;

bool cond(ll s) {
  ll sets = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] * f[i] > s) {
      ll ap = floor(s/f[i]);
      sets += a[i] - ap;
    }
  }
  return sets <= k;
}

int main() {
  cin >> n;
  cin >> k;

  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
   for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    f.push_back(tmp);
  }
  sort(a.begin(), a.end());
  sort(f.begin(), f.end(), greater<ll>());

  ll l = 0;
  ll r = 1e12;
  while (l < r) {
   ll mid =(l+r)/2;
    if (cond(mid)) {
      r = mid;
    } else {
     l = mid + 1; 
    }
  }
  cout << l << endl;
}
