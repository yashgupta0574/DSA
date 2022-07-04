// watch abdul bari video youtube
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

int dp[N][N];

/*int mcm(vi &a, int i, int j)
{
    if (dp[i][j] != MOD)
    {
        return dp[i][j];
    }
    if (i == j)
    {
        dp[i][j] = 0;
        return dp[i][j];
    }
    if (j - i == 1)
    {
        dp[i][j] = a[i - 1] * a[i] * a[j];
        return dp[i][j];
    }
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], mcm(a, i, k) + mcm(a, k + 1, j) + a[i - 1] * a[k] * a[j]);
    }
    return dp[i][j];
}*/

int main()
{
    // memoization
    /*rep(i, 0, N)
    {
        rep(j, 0, N)
        {
            dp[i][j] = MOD;
        }
    }
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    cout << mcm(a, 1, n - 1) << endl;*/
    // iterative
    rep(i, 0, N)
    {
        rep(j, 0, N)
        {
            dp[i][j] = MOD;
        }
    }
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    int j;
    for (int gap = 0; gap <= n - 1; gap++)
    {
        for (int i = 1; i <= n - gap - 1; i++)
        {
            j = i + gap;
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else if (j - i == 1)
            {
                dp[i][j] = a[i - 1] * a[i] * a[j];
            }
            else
            {
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j]);
                }
            }
        }
    }
    cout << dp[1][n - 1] << endl;
    return 0;
}
