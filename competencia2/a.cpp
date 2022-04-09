#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template <class T>
struct SegmentTree {
  T (*merge)(T, T);
  int n;
  vector<T> ST;
  void build(int i, int l, int r, vector<T> &values) {
    if (l == r) {
      ST[i] = values[l];
      return;
    }
    build(i << 1, l, (l + r) >> 1, values);
    build(i << 1 | 1, (l + r) / 2 + 1, r, values);
    ST[i] = merge(ST[i << 1], ST[i << 1 | 1]);
  }

  SegmentTree(vector<T> &values, T (*merge)(T a, T b)) : merge(merge) {
    n = values.size();
    ST.resize(n << 2 | 3);
    build(1, 0, n - 1, values);
  }

  void update(int i, int l, int r, int pos, T val) {
    if (r < pos or l > pos) return;
    if (l == r) {
      ST[i] = val;
      return;
    }
    update(i << 1, l, (l + r) >> 1, pos, val);
    update(i << 1 | 1, (l + r) / 2 + 1, r, pos, val);
    ST[i] = merge(ST[i << 1], ST[i << 1 | 1]);
  }

  void update(int pos, T val) { update(1, 0, n - 1, pos, val); }

  T query(int i, int l, int r, int a, int b) {
    if (l >= a and r <= b) return ST[i];
    int mid = (l + r) >> 1;
    if (mid < a) return query(i << 1 | 1, mid + 1, r, a, b);
    if (mid >= b) return query(i << 1, l, mid, a, b);
    return merge(query(i << 1, l, mid, a, b),
                 query(i << 1 | 1, mid + 1, r, a, b));
  }

  T query(int a, int b) {
    if (a > b)
      return merge(query(1, 0, n - 1, 0, b), query(1, 0, n - 1, a, n - 1));
    return query(1, 0, n - 1, a, b);
  }
};

struct node {
  int val;
  node(int new_val) {
    val = new_val;
  } 
  node(){};
};

node merge(node a, node b) {
  return node(a.val | b.val);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, i, x;
  int s;
  cin >> n >> m;
  int sz = pow(2,n);
  vector<node> v;
  for (int i = 0; i < sz; i++)
  {
      cin >> s;
      v.push_back(node(s));
  }
  
  SegmentTree<node> S(v, merge);
  while (m--) {
    cin >> i;
    cin >> x;
    S.update(i,x);
    cout << S.query(0, sz+1).val << "\n";
  }
  return 0;
}