// count number of binary strings is a case of fibonacci series so watch video 180
// constraint is that there should not be consecutive 1's;
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
    // 0101000111
    int n;
    cin >> n;
    vi one(n + 1, 0);
    vi zero(n + 1, 0);
    // one denotes string ending with 1
    // 0 denotes string ending with 0
    one[0] = zero[0] = 1; // teo case either 1 or 0 for n=1
    rep(i, 1, n)
    {
        one[i] = zero[i - 1];
        zero[i] = one[i - 1] + zero[i - 1];
    }
    cout << one[n - 1] + zero[n - 1] << endl;

    return 0;
}
// ans=one[n - 1] + zero[n - 1] =zero[n-2]+zero[n-1]==resembles fibonacci