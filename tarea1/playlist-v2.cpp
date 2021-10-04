#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n;
  cin >> k;
  vector<pair<long long, long long>> v;
  multiset<long long> s;
  // leer input y ordenar pares (belleza, tiempo)
  for (int i = 0; i < n; i++) {
    long long t;
    cin >> t;
    long long b;
    cin >> b;
    v.push_back(pair<long long, long long>(b, t));
  }
  sort(v.begin(), v.end(), greater<pair<long long, long long>>());
  // comienza la resolucion
  long long sum = 0;
  long long res = 0;
  // fijar cancion
  for (auto it = v.begin(); it != v.end(); it++) {
    sum += it->second;
    s.insert(it->second);
    if (s.size() > k) {
      sum -= *s.begin();
      s.erase(s.begin());
    }
    if (res < sum * it->first) {
      res = sum * it->first;
    }
  }
  cout << res;
  return 0;
}