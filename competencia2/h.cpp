#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef long long ll;
int n,k;
int main() {
  cin >> n >> k;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
      v.push_back(i+1);
  }
  int eliminados = 0;
  int dead = 0;
  while(eliminados < n){
      dead = (dead + k)%v.size();
      cout << v[dead] << endl;
      v.erase(v.begin()+dead);
      eliminados += 1;
  }
  return 0;
}

/* v.size() = 7. 6
   5 mod 6 + 1

*/