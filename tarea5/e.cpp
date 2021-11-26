#include <string.h>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using ll = long long;
using namespace std;

template <class T>
vector<int> prefix(T &S)
{
    vector<int> P(S.size());
    P[0] = 0;
    for (int i = 1; i < S.size(); ++i)
    {
        P[i] = P[i - 1];
        while (P[i] > 0 && S[P[i]] != S[i])
            P[i] = P[P[i] - 1];
        if (S[P[i]] == S[i])
            ++P[i];
    }
    return P;
}

vector<int> prefix_hash(string &s)
{
    vector<int> v(s.size(), 0);
    int n = s.size() - 1;
    int m = 1e9 + 7;
    int z = 127;
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res += ((int)s[i] * (int)pow(z, i)) % m;
    }
    v[s.size() - 1] = res;
    for (int i = s.size() - 2; i >= 0; i--)
    {
        v[i] = v[i + 1] * z + s[i];
    }
    return v;
}

int shash(string &s)
{
    int n = s.size() - 1;
    int m = 1e9 + 7;
    int z = 127;
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res += ((int)s[i] * (int)pow(z, i)) % m;
    }
    return res;
}

int main()
{
    int n,m; cin >> n >> m;
    vector<string> nums(n,"");
    // vector<vector<int>> ints(n);
    vector<pair<int,int>> ms;
    while(m--){
        int a,b; cin >> a >> b;
        auto tmp = pair<int,int>(a,b);
        ms.push_back(tmp);
    }
    // sort(ms.begin(), ms.end());
    std::sort(std::begin(ms),
          std::end(ms),
          [&](std::pair<int, int> const& lhs, std::pair<int, int> const& rhs)
          {     
              int lmx = max(lhs.first,lhs.second);
              int lmn = min(lhs.first, lhs.second);
              int rmx = max(rhs.first,rhs.second);
              int rmn = min(rhs.first,rhs.second);
              return max(lmx - lmn, n - (lmx - lmn)) > min(rmx - rmn, n - (rmx - rmn));
          });
    for (auto &&i : ms){
        int mx = max(i.first,i.second);
        int mn = min(i.first,i.second);
        // ints[mx-1].push_back(n-(mx-mn));
        // ints[mn-1].push_back(mx-mn);
        nums[mx-1].append(to_string(n - (mx - mn)).append(" "));
        nums[mn-1].append(to_string(mx-mn).append(" "));
    }
    // for (int i = 0; i < n; i++){
    //     sort(ints[i].begin(), ints[i].end());
    //     for (auto &&e : ints[i])
    //     {
    //         nums[i].append(to_string(e));
    //     }
    // }
    
    string r = std::accumulate( std::next(nums.begin()), nums.end(), nums[0],  [](std::string a, std::string b) {return a + "$" + b;});
    r.append("$");
    cout << r << endl;
    int l = r.length();
    string tmp = "$";
    tmp = tmp.append(r);
    r = r.append(tmp);
    // cout << r << endl;
    vector<int> res = prefix(r);
    // for (auto &&i : res)
    // {
    //     cout << i << " ";
    // }
    if(res[2*l-1] >= l){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No";
    return 0;
}

