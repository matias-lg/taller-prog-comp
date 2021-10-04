#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int main() {
  int n;
  do {
    cin >> n;
    if (n == 0) {
      break;
    }
    long long res = 0;
    multiset<long long> s;
    int k;
    for (int i = 0; i < n; i++) {
      cin >> k;
      // insert numbers into set
      long long num;
      for (int j = 0; j < k; j++) {
        cin >> num;
        s.insert(num);
      }
      // remove max and min - update result
      long long min = *s.begin();
      long long max = *(prev(s.end()));
      res += max - min;
      s.erase(s.begin());
      s.erase(prev(s.end()));
    }
    cout << res << endl;
  } while (n != 0);
  return 0;
}
