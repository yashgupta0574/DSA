#include "bits/stdc++.h"
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int len = sqrtl(n) + 1;
    cout << len;
    vector<int> b(len);
    for (int i = 0; i < len; i++)
    {
        b[i / len] += a[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        for (int i = l; i <= r;)
        {
            if (i % len == 0 && i + len - 1 <= r)
            {
                sum += b[i / len];
                i += len;
            }
            else
            {
                sum += a[i];
                i++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}