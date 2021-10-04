#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

// [1 2] -> 2 []
// [1 2 3] -> 3 [1] -> 4 [];
// [1 2 1 3 2 2 2 2 3] -> 2 [2 2 2 2] -> 10 []
// dp[n] = (#n)
// score(n) = dp[n]*n - (dp[n-1]*(n-1)+dp[n+1]*(n+1))
// score(n+2) = dp[n+2]*(n+2) - score(n-1) + score(n-2)
//max(score)
// elimino n: dp[n-1][1] -= 1 y dp[n+1][0] -= 1
// max(score)
ll dp[(int)1e5 + 3];
int main()
{
    ll res = 0;
    ll n;
    cin >> n;
    vector<ll> v;
    set<ll> s;
    ll mmin = 100009;
    for (ll i = 0; i < n; i++)
    {
        ll tmp;
        mmin = min(mmin, tmp);
        cin >> tmp;
        v.push_back(tmp);
        dp[tmp]++;
    }
    ll n1 = dp[1];
    ll m = n1;
    ll n2 = 0;
    for (int i = 2; i < 100001; i++)
    {
        m = max((n2 + dp[i] * i), n1);
        n2 = n1;
        n1 = m;
    }
    cout << m;

    return 0;
}
