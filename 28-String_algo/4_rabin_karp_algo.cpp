#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define int long long
const int m = 1e9 + 7, N = 1e2;
int p = 31; // we can take p any number > 26
vector<long long> powers(N);

int32_t main()
{
    powers[0] = 1;
    rep(i, 1, N)
    {
        powers[i] = (powers[i - 1] * p) % m;
    }
    string t = "4th sem just completed";
    string a = "let";
    int T = t.size();
    int A = a.size();
    vector<long long> hash(T + 1, 0);
    rep(i, 0, T)
    {
        hash[i + 1] = (hash[i] + (t[i] - 'a' + 1) * powers[i]) % m;
    }
    int hs = 0;
    rep(i, 0, A)
    {
        hs = (hs + (a[i] - 'a' + 1) * powers[i]) % m;
    }
    rep(i, 0, T - A + 1)
    {
        int curr_h = (hash[i + A] - hash[i] + m) % m; //+m because h[i+A] can be less than h[i] so that ans would not come negative
        if (curr_h == (hs * powers[i]) % m)
        {
            cout << "Found at:" << i << endl;
        }
    }

    return 0;
}