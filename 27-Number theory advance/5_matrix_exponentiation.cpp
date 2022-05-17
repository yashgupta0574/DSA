#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

vvi multiply(vvi &a, vvi &b)
{
    int n = a.size();
    vvi ans(n, vi(n, 0));
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            rep(k, 0, n)
            {
                ans[i][j] += a[i][k] * b[j][k];
            }
        }
    }
    return ans;
}

vector<vector<int>> matrixExponentiate(vector<vector<int>> &a, int n)
{
    int sz = a.size();
    if (n == 0)
    {
        vvi ans(sz, vi(sz, 0));
        rep(i, 0, sz)
        {
            ans[i][i] = 1;
        }
        return ans;
    }
    if (n == 1)
    {
        return a;
    }
    vvi temp = matrixExponentiate(a, n / 2);
    vvi ans = multiply(temp, temp);
    if (n % 2 != 0)
    {
        ans = multiply(ans, a);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a = {{1, 1}, {1, 0}};
    vector<vector<int>> ans = matrixExponentiate(a, n);
    int sz = ans.size();
    rep(i, 0, sz)
    {
        rep(j, 0, sz)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}