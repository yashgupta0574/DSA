#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

bool cc(pair<int, int> a, pair<int, int> b)
{
    double v1 = (double)a.ff / a.ss;
    double v2 = (double)b.ff / b.ss;
    return v1 > v2;
}

int main()
{
    int n;
    cin >> n;
    vii v(n);
    rep(i, 0, n)
    {
        cin >> v[i].ff >> v[i].ss; // ff=value and ss=weight
    }

    int w;
    cin >> w;
    sort(v.begin(), v.end(), cc); // cc=custom comparator
    double ans = 0;
    rep(i, 0, n)
    {
        if (w > v[i].ss)
        {
            ans += v[i].ff;
            w -= v[i].ss;
        }
        else
        {
            double vw = (double)v[i].ff / v[i].ss;
            ans += (double)vw * w;
            w = 0;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}