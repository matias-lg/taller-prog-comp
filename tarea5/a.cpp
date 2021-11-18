#include <string.h>

#include <iostream>
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
    int z = 127;
    int t;
    cin >> t;
    string s, p;
    while (t--)
    {
        cin >> s >> p;
        vector<int> prefix_hash_s = prefix_hash(s);
        int p_size = p.size();
        int p_hash = shash(p);
        vector<int> appearances;

        string kmpstring = p + "#" + s;
        vector<int> kmp = prefix<string>(kmpstring);

        for (int i = p_size; i < kmp.size(); i++)
        {
            if (kmp[i] == p_size)
            {
                appearances.push_back(i-p_size*2+1);
            }
        }
        if (appearances.size() == 0)
        {
            cout << "Not Found";
        }

        else
        {
            cout << appearances.size() << endl;
            for (int i = 0; i < appearances.size(); i++)
            {
                cout << appearances[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// s[0..n] # ppppps[0..n]pppp
// i - (n - 1) - (n + 1) = i - 2n