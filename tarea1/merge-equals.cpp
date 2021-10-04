#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  set<pair<int, long long>> res;
  int n;
  cin >> n;
  // set de pares
  set<pair<long long, int>> s;
  // insertar valores en el set
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    s.insert(pair<long long, int>(val, i));
  }
  // do stuff
  while (s.begin() != s.end()) {
    if (s.begin()->first == next(s.begin())->first) {
      auto tmp = pair<long long, int>(next(s.begin())->first * 2,
                                      next(s.begin())->second);
      s.erase(s.begin());
      s.erase(s.begin());
      s.insert(tmp);
    } else {
      res.insert(pair<int, long long>(s.begin()->second, s.begin()->first));
      s.erase(s.begin());
    }
  }
  cout << res.size() << endl;
  // print vector elements
  for (auto it = res.begin(); it != res.end(); it++) {
    cout << it->second << " ";
  }
}
