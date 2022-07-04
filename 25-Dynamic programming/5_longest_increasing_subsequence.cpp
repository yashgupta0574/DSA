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

int dp[N];
int maxm = 0; // it calculates the highest number in current longest subsequence if number is larger than last greater element in array

int Lis(vi &a, int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = 1;
    rep(i, 0, n)
    {
        if (a[n] > a[i])
        {
            dp[n] = max(dp[n], 1 + Lis(a, i));
        }
    }
    return dp[n];
}

int main()
{
    // memoization
    rep(i, 0, N)
    {
        dp[i] = -1;
    }
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    Lis(a, n - 1);
    rep(i, 0, n)
    {
        maxm = max(maxm, dp[i]);
    }
    cout << maxm << endl;

    // iterative
    /*int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    vi dp(n, 1);
    int ans = 0;
    rep(i, 1, n)
    {
        rep(j, 0, i)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << endl;*/
    return 0;
}
// 1 3 6 7 9 4 10 5 6