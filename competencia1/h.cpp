#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
int main() {
  int a[4];
  string s;
  ll res = 0;
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    int num = s[i] - '0';
    res += a[num - 1];
  }
  cout << res;
  return 0;
}