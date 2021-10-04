#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int n;
int main() {
  do {
    cin >> n;
    if (n == 0) {
      break;
    }
    long long total = 0;
    vector<int> yesterday = {};
    for (int i = 0; i < n; i++) {
      long long bills;
      // numero de cuentas
      cin >> bills;
      long long x;
      // valores de cuentas
      for (int k = 0; k < bills; k++) {
        cin >> x;
        yesterday.insert(yesterday.end(), x);
      }
      // encontrar minimos y maximos
      long long min = yesterday[0];
      long long max = yesterday[1];
      int max_el = 1;
      int min_el = 0;
      for (int i = 0; i < yesterday.size(); i++) {
        if (yesterday[i] < min) {
          min = yesterday[i];
          min_el = i;
        } else if (yesterday[i] > max) {
          max = yesterday[i];
          max_el = i;
        }
      }
      if (max_el > min_el) {
        yesterday.erase(yesterday.begin() + max_el);
        yesterday.erase(yesterday.begin() + min_el);
      } else {
        yesterday.erase(yesterday.begin() + min_el);
        yesterday.erase(yesterday.begin() + max_el);
      }
      total += max - min;
    }
    // calcular y eliminar del vector
    cout << total << endl;
  } while (n != 0);
  return 0;
}
