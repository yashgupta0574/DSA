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
vi a;

int solve(int i, int j)
{
    if (i == j)
    {
        return a[i];
    }
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int l = a[i] + min(solve(i + 2, j), solve(i + 1, j - 1)); //if we select a[i]th coin then opponent select optimally
    //so that other opponet have loss
    int r = a[j] + min(solve(i + 1, j - 1), solve(i, j - 2)); //if we select a[j]th coin
    dp[i][j] = max(l, r);
    return dp[i][j];
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    a = vi(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    cout << solve(0, n - 1) << endl;
    return 0;
}
