// ugly nos are those whose prime factorization include 2,3and 5 only
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
    int n = 10;
    // cin >> n;
    vi dp(n + 1, 1);
    // int c2 = 0, c3 = 0, c5 = 0;
    int c2(0), c3(0), c5(0); // it means c2=c3=c5=0
    rep(i, 1, n + 1)
    {
        // dp[i] = min(2 * dp[c2], min(3 * dp[c3], 5 * dp[c5]));
        dp[i] = min({2 * dp[c2], 3 * dp[c3], 5 * dp[c5]});
        if (dp[i] == 2 * dp[c2])
        {
            c2++;
        }
        if (dp[i] == 3 * dp[c3])
        {
            c3++;
        }
        if (dp[i] == 5 * dp[c5])
        {
            c5++;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
