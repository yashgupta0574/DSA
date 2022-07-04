#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

bool cc(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    rep(i, 0, n)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end(), cc); // cc=custom comparator
    int take = 1;
    int end = v[0][1];
    rep(i, 0, n)
    {
        if (v[i][0] > end)
        {
            take++;
            end = v[i][1];
        }
    }
    cout << take << endl;
    return 0;
}