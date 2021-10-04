#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

long long x(vector<long long> v, long long h) {
  long long res = 0;
  for (long long i : v) {
    res += max((long long)0, h - i);
  }
  return res;
}

long long y(vector<long long> v, long long h) {
  long long sum = accumulate(v.begin(), v.end(), (long long)0);
  long long n = v.size();
  return sum - n * h + x(v, h);
}

long long m(vector<long long> v, long long h) { return min(x(v, h), y(v, h)); }

long long c(vector<long long> v, long long h, int a, int r, int M) {
  // return m(v, h) * (M - a - r) + x(v, h) * a + y(v, h) * r;
  long long mm = m(v, h);
  return mm * M + (x(v, h) - mm) * a + (y(v, h) - mm) * r;
  // unsigned long long sum = accumulate(v.begin(), v.end(), (long long)0);
  // unsigned long long n = v.size();
  // return (sum - n * h) * r + (x(v, h) - m(v, h)) * (a + r - M);
}

long long d(vector<long long> v, long long h, int a, int r, int M) {
  return c(v, h, a, r, M) - c(v, h + 1, a, r, M);
}

bool cond(vector<long long> v, long long h, int a, int r, int M) {
  return d(v, h, a, r, M) <= 0;
}

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
  long long R = 1e9 + 1;
  long long mid;
  long long minp = LLONG_MAX;
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