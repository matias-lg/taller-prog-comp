#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n;
  cin >> k;
  multiset<pair<long long, long long>> s;
  // leer input y ordenar pares (belleza, tiempo)
  for (int i = 0; i < n; i++) {
    long long t;
    cin >> t;
    long long b;
    cin >> b;
    s.insert(pair<long long, long long>(b, t));
  }
  // comienza la resolucion
  long long res = 0;
  // fijar cancion
  for (auto it = s.begin(); it != s.end(); it++) {
    long long tmpres = 0;
    multiset<long long> r;
    for (auto it2 = it; it2 != s.end(); it2++) {
      if (r.size() < k) {
        tmpres += it2->second;
        r.insert(it2->second);
      } else {
        if (*r.begin() < it2->second) {
          tmpres += it2->second - *r.begin();
          r.erase(r.begin());
          r.insert(it2->second);
        }
      }
    }
    tmpres *= it->first;
    if (tmpres > res) {
      res = tmpres;
    }
  }
  cout << res;
  return 0;
}