#include <math.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

ll m = 1e9+7;
int z = 127;

template<class T>
void pv(vector<T> &v){
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int int_pow(int x, int y) {
  ll res = 1;
  for (int j = 1; j <= y; j++) {
    res *= x;
  }
  return res;
}

vector<int> prefix_hash(string &s) {
  vector<int> v(s.size(), 0);
  v[s.size() - 1] = s[s.size() - 1];
  for (int i = s.size() - 2; i >= 0; i--) {
    v[i] = ((v[i + 1] * z) + s[i]) % m;
  }
  return v;
}
int hlr(vector<int> &v, int l, int r) {
  return (v[l] - (v[l + r] * int_pow(z, r))) % m;
}

int main() {
  string s;
  cin >> s;
  string rs = s;
  reverse(rs.begin(), rs.end());
  vector<int> h = prefix_hash(s);
  vector<int> hr = prefix_hash(rs);
  int l = 0;
  int n = s.size();
  int r = n-1;
  int i = 2;
  while(i<=r-l+1){
    if (hlr(h,l,i/2) == hlr(hr,n-l-i,i/2)){
      l += i/2;
      i = 2;
      continue;}
      i+=2;}
  while(i<=r-l+1){
    if(hlr(h,r-i+1,i/2) == hlr(hr,n-r-1,i/2)){
      r -= i/2;
      i = 2;
      continue;}
    i += 2;}
  cout << r-l+1;
  return 0;
}