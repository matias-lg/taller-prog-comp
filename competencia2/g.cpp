#include <bits/stdc++.h>

#include <iostream>

using namespace std;
typedef long long ll;

int n, k, a, b;
int main() {
  cin >> n;
  vector<pair<int, int>> v;
  vector<pair<int, int>> v_original;
  vector<int> dp(n);
  while (n--) {
    // 18,2 -> [19,19]
    // 20,1 -> [21,20]
    // 10,15 -> [11,24]
    // 16,5 -> [17,20]
    cin >> a >> b;
    v_original.push_back(pair<int, int>(a, b));
    v.push_back(pair<int, int>(a, b));
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 0; i--)
  {
      int p = v[i].first;
      int l = v[i].first + 1;
      int r = v[i].first + v[i].second - 1;
      for(int k = l; k <= min((int)v.size()-1, r); k+=dp[k]){
          dp[i] += dp[k];
      }
      dp[i]++;
      cout << dp[i] << endl;
  }
  cout << "out" << endl;



// for (int i = 0; i < v.size(); i++){
//     cout << dp[v_original[i].first] << endl;
// }
  return 0;
}
