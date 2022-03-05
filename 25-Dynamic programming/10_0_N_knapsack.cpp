#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 1e2 + 2, MOD = 1e9 + 1;

int main()
{
    int n = 5, W = 11;
    vi wt = {3, 2, 4, 5, 1};
    vi val = {4, 3, 5, 6, 1};
    vi dp(W + 1, 0);
    rep(i, 0, W + 1)
    {
        rep(j, 0, n)
        {
            if (i - wt[j] >= 0)
            {
                dp[i] = max(dp[i], val[j] + dp[i - wt[j]]);
            }
        }
    }
    cout << dp[W] << endl;
    return 0;
}
