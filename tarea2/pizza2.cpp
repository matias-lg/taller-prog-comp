#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int N, S;
ll ts = 0;
vector<vector<ll>> vals;

ll h(ll n1, ll tot, ll s) {
  ll cnt1 = n1;
  ll cnt2 = tot - n1;
  ll res = 0;
  ll i = 0;
  while (cnt1 > 0 && i < s) {
    if (cnt1 - vals[i][1] >= 0) {
      res += vals[i][1] * vals[i][2];
      cnt1 -= vals[i][1];
    } else {
      res += cnt1 * vals[i][2];
      res += (vals[i][1] - cnt1) * vals[i][3];
      cnt2 -= vals[i][1] - cnt1;
      cnt1 = 0;
    }
    i += 1;
  }
  while (cnt2 > 0 && i < s) {
    res += vals[i][1] * vals[i][3];
    cnt2 -= vals[i][1];
    i += 1;
  }
  return res;
}

int main() {
  cin >> N;
  cin >> S;
  for (int i = 0; i < N; i++) {
    int s, a, b;
    cin >> s;
    cin >> a;
    cin >> b;
    ts += s;
    vector<ll> tmp;
    tmp.push_back(a - b);
    tmp.push_back(s);
    tmp.push_back(a);
    tmp.push_back(b);
    vals.push_back(tmp);
  }
  ll p = ceil((float)ts / S);
  // cout << slices << endl;
  ll dummy = S * p - ts;
  if (ts > S) {
    vector<ll> dv;
    dv.push_back(0);
    dv.push_back(dummy);
    dv.push_back(0);
    dv.push_back(0);
    vals.push_back(dv);
  }
  sort(vals.begin(), vals.end(),
       [](const vector<ll>& a, const vector<ll>& b) { return a[0] > b[0]; });

  // filtrar por numero de tortas
  //vector<ll> posible;
  //for (ll i = 0; i < S * p + 1; i++) {
  //  if (ceil((float)i / S) + ceil((float)(S * p - i) / S) <= p) {
  //    posible.push_back(i);
  //  }
 // }

  ll res = 0;
  ll l = 0;
  ll r = p;
  ll sz = vals.size();
  while (l < r) {
    ll mid = (l + r) / 2;
    ll ch = h(mid*S, S * p, sz);
    ll nh = h((mid + 1)*S, S * p, sz);
    if (nh - ch > 0) {
      l = mid + 1;
    } else {
     r = mid;
    }
  }
  cout << h(l*S, S*p, sz) << endl;
}
