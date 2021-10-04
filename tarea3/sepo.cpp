#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> a(n);
    vector<ll> dp(n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    for (int i = 1; i < n; i++)
    {
        ll imin = (1e4 + 1) * 1e5;
        for (int j = max(0, i - k); j < i; j++)
        {
            ll cmin = (abs(a[i] - a[j]) + dp[j]);
            imin = min(cmin, imin);
        }
        dp[i] = imin;
    }
    cout << dp.at(n - 1);
    return 0;
}
