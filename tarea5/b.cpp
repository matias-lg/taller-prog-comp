#include <math.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>
using ll = unsigned long long;
using namespace std;

ll m = UINT64_MAX;
int z = 127;
vector<int> dp((int)5 * 1e6 + 100, 0);

ll int_pow (ll x, ll y) {
  ll res = 1;
  for (int j = 1; j <= y; j++){  res *= x;}
  return res;
}

vector<ll> prefix_hash(string &s) {
  vector<ll> v(s.size(), 0);
  v[s.size() - 1] = s[s.size() - 1];
  for (int i = s.size() - 2; i >= 0; i--) {
    v[i] = ((v[i + 1] * z) + s[i]) % m;
  }
  return v;
}
int hlr(vector<ll> &v, ll l, ll r) {
  return (v[l] - (v[l+r] * int_pow(z,r))%m) % m;
}
int main() {
  string s;
  cin >> s;
  dp[0] = 1;
  int n = s.size();
  int res = 1;
  vector<ll> h(n,0);
  h[n-1] = s[n - 1];
  vector<ll> hr(n,0);
  hr[n - 1] = s[0];
  for (int i = n - 2; i >= 0; i--){
    hr[i] = (hr[i+1]*z+s[n-i-1])%m;
    h[i] = (h[i+1]*z+s[i])%m;
    
    }
  for (int i = 1; i < n; i++) {
    if (hlr(h, 0, i) == hlr(hr,n-i-1,i)) dp[i] = 1 + dp[(i + 1) / 2 - 1];
    res += dp[i];}
  std::cout << res << endl;
  return 0;
}
