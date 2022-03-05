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

//int dp[N];

int main()
{
    //iterative
    /*int m;
    cin >> m;
    vi s(m);
    rep(i, 0, m)
    {
        cin >> s[i];
    }
    int x;
    cin >> x;
    vvi dp(m + 1, vi(x + 1, 0));
    dp[0][0] = 1;
    rep(i, 1, m + 1)
    {
        rep(j, 0, x + 1)
        {
            if (j - s[i - 1] >= 0)
            {
                dp[i][j] += dp[i][j - s[i - 1]]; //if we take the ith coin
            }
            dp[i][j] += dp[i - 1][j]; //if we donot take the coin
        }
    }
    cout << dp[m][x];*/

    //iterative with space optimization
    int m;
    cin >> m;
    vi s(m);
    rep(i, 0, m)
    {
        cin >> s[i];
    }
    int x;
    cin >> x;
    vi dp(x + 1, 0);
    dp[0] = 1;
    rep(i, 0, m+1)
    {
        rep(j, 0, x + 1)
        {
            if ((j - s[i-1]) >= 0)
            {
                dp[j] += dp[j - s[i-1]];
            }
            cout << dp[j] << " ";
        }
        cout << endl;
    }
    cout << dp[x] << endl;
    return 0;
}