#include "bits/stdc++.h"
using namespace std;
int rootn;
const int N = 1e2;
int n;
struct Q
{
    int l, r, idx;
};
Q q[N];

bool compare(Q q1, Q q2)
{
    if (q1.l / rootn == q2.l / rootn)
    {
        return q1.r < q2.r;
    }
    return q1.l < q2.l;
}

signed main()
{
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    rootn = sqrtl(n);
    int queries;
    cin >> queries;
    for (int i = 0; i < queries; i++)
    {
        int l, r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    sort(q, q + queries, compare);
    vector<int> ans(queries);
    int curr_l = 0, curr_r = -1, l, r;
    int curr_ans = 0;
    vector<int> freq(n, 0);
    for (int i = 0; i < queries; i++)
    {
        l = q[i].l;
        r = q[i].r;
        while (curr_r < r)
        {
            curr_r++;
            freq[a[curr_r]]++;
            if (freq[a[curr_r]] == 1)
            {
                curr_ans++;
            }
        }
        while (curr_l < l)
        {
            freq[a[curr_l]]--;
            if (freq[a[curr_l]] == 0)
            {
                curr_ans--;
            }
            curr_l++;
        }
        while (curr_r > r)
        {
            freq[a[curr_r]]--;
            if (freq[a[curr_r]] == 0)
            {
                curr_ans--;
            }
            curr_r--;
        }
        while (curr_l > l)
        {
            curr_l--;
            freq[a[curr_l]]++;
            if (freq[a[curr_l]] == 1)
            {
                curr_ans++;
            }
        }
        ans[q[i].idx] = curr_ans;
    }
    for (int i = 0; i < queries; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
/*
9
1 2 1 3 4 5 5 6 1
5
0 2
0 3
1 2
0 8
2 4
*/