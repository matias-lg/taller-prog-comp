#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;

int main() {
  ll n = 0;
  ll t = 0;
  ll mint = 1e9 + 1;

  cin >> n >> t;
  ll tot = 0;
  ll len = n;
  vector<ll> as(n, 0);
  for (ll i = 0; i < n; i++) {
    cin >> as[i];
    mint = min(as[i], mint);
    tot += as[i];
  }
  ll ans = 0;
  ll neg = 0;
  while (t >= mint || neg == n) {
    // ver cuantas veces podemos comprar todo de una
    ans += (t / tot) * len;
    t -= (t / tot) * tot;

    tot = 0;
    len = 0;

    for (int i = 0; i < n; i++) {
      if (as[i] != -1) {
        tot += as[i];
        len++;
        if (t >= as[i]) {
          t -= as[i];
          ans++;
        } else {
          tot -= as[i];
          len--;
          as[i] = -1;
          neg++;
        }
      }
    }
  }

  cout << ans;
  return 0;
}
//   cout << "puesto: " << i + 1 << " precio: " << as[i] << " t: " << t
//        << endl;