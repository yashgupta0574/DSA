#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int mod = 1e9 + 7, N = 1e2;
int p = 31; // we can take p as any number > 26
vector<long long> powers(N);

int main()
{
    powers[0] = 1;
    rep(i, 1, N)
    {
        powers[i] = (powers[i - 1] * p) % mod;
    }
    string t = "I got an EID(SDE) intern at GE healthcare";
    string a = "tern";
    int n = t.size();
    int m = a.size();
    vector<long long> hash(n + 1, 0);
    rep(i, 0, n)
    {
        hash[i + 1] = (hash[i] + (t[i] - 'a' + 1) * powers[i]) % mod;
    }
    int hs = 0;

    rep(i, 0, m)
    {
        hs = (hs + (a[i] - 'a' + 1) * powers[i]) % mod;
    }

    rep(i, 0, n - m + 1)
    {
        int curr_h = (hash[i + m] - hash[i] + mod) % mod;
        if (curr_h == (hs * powers[i]) % mod)
        {
            cout << "Found at:" << i << endl;
        }
    }
    return 0;
}