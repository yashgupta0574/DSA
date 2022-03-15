#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int n;
    cin >> n;
    vi v(n);
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    int prev = 0, curr = 0, jumps = 0;
    rep(i, 0, n)
    {
        if (i > prev)
        {
            jumps++;
            prev = curr;
        }
        curr = max(curr, i + v[i]);
    }
    cout << jumps << endl;

    return 0;
}
// 9
// 1 3 5 8 9 2 6 7 6 8 9