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

int dp[50][50][50];

int lcs(string &s1, string &s2, string &s3, int n, int m, int l)
{
    if (n == 0 || m == 0 || l == 0)
    {
        return 0;
    }
    if (dp[n][m][l] != -1)
    {
        return dp[n][m][l];
    }
    if (s1[n - 1] == s2[m - 1] && s2[m - 1] == s3[l - 1])
    {
        return dp[n][m][l] = 1 + lcs(s1, s2, s3, n - 1, m - 1, l - 1);
    }
    int a = lcs(s1, s2, s3, n - 1, m, l);
    int b = lcs(s1, s2, s3, n, m - 1, l);
    int c = lcs(s1, s2, s3, n, m, l - 1);
    return dp[n][m][l] = max({a, b, c});
}

int main()
{
    //memoization
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int n = s1.size();
    int m = s2.size();
    int l = s3.size();
    memset(dp, -1, sizeof(dp));

    cout << lcs(s1, s2, s3, n, m, l) << endl;

    return 0;
}
/*
apna
collegeap
annnp
*/