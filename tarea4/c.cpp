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
  //   ll left, right, total, best;
  ll min;
  //   node(ll val) { left = right = total = best = val; }
  node(ll val) {
    min = val;
  }  //   node(ll l, ll r, ll t, ll b) {
     //     left = l;
     //     right = r;
     //     total = t;
     //     best = b;
     //   }
  node(){};
};

node merge(node a, node b) {
  return node(min(a.min, b.min));
  //   return node(max({a.total + b.left, a.left}),
  //               max({a.right + b.total, b.right}), a.total + b.total,
  //               max({a.best, b.best, a.right + b.left}));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  ll s;
  cin >> n;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> s;
    v[i] = node(s);
  }

  SegmentTree<node> S(v, merge);  // Primero el vector con los valores de las
                                  // hojas Después la función que calcula.
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l;
    cin >> r;
    cout << S.query(l, r).min << "\n";
  }
  return 0;
}