// https://www.spoj.com/problems/EXPEDI/
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pii> a(n);
        rep(i, 0, n)
        {
            cin >> a[i].ff >> a[i].ss; // ff=distanc of stop from town and ss=amount of fuel
        }
        int l, p; // l=distance of truck from town
        cin >> l >> p;
        rep(i, 0, n)
        {
            a[i].ff = l - a[i].ff; // ff=distanc of stop from truck
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int fuel = p;
        priority_queue<int, vi> pq;
        bool flag = 0;
        rep(i, 0, n)
        {
            if (fuel >= l)
            {
                break;
            }
            while (fuel < a[i].ff)
            {
                if (pq.empty())
                {
                    flag = 1;
                    break;
                }
                fuel += pq.top();
                pq.pop();
                ans++;
            }
            if (flag)
                break;
            pq.push(a[i].ss);
        }
        if (flag)
        {
            cout << "-1" << endl;
            continue; // continue for other test cases
        }
        while (!pq.empty() && fuel < l)
        {
            fuel += pq.top();
            pq.pop();
            ans++;
        }
        if (fuel < l)
        {
            cout << "-1" << endl;
        }
        cout << ans << endl;
    }
    return 0;
}