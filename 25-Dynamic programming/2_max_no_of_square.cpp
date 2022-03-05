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

/*int dp[N];

int minsquare(int n)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
    {
        return n;
    }
    if (dp[n] != MOD)
    {
        return dp[n];
    }
    for (int i = 1; i * i <= n; i++)
    {
        dp[n] = min(dp[n], 1 + minsquare(n - i * i));
    }
    return dp[n];
}*/

int main()
{
    //memoization{top to bottom}
    /*int n;
    cin >> n;
    rep(i, 0, n + 1)
    {
        dp[i] = MOD;
    }
    cout << minsquare(n) << endl;*/

    //tabulation(bottom up method)
    int n;
    cin >> n;
    vi dp(n + 1, MOD);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 1; i * i <= n; i++)
    {
        for (int j = 0; i * i + j <= n; j++)
        {
            dp[i * i + j] = min(dp[i * i + j], 1 + dp[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}