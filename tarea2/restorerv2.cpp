#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int n, a, r, M;
  cin >> n;
  cin >> a;
  cin >> r;
  cin >> M;
  M = min(M, a + r);
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    long long k;
    cin >> k;
    v.push_back(k);
  }
  long long l = 0;
  long long R = accumulate(v.begin(), v.end(), (long long)0);
  long long mid;
  unsigned long long minp = ULLONG_MAX;
  while (l < R) {
    mid = (l + (R - l) / 2);
    // cout << "mid: " << mid << " c: " << c(v, mid, a, r, M) << endl;
    if (cond(v, mid, a, r, M)) {
      minp = min(minp, c(v, mid, a, r, M));
      R = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << minp << endl;
  return 0;
}