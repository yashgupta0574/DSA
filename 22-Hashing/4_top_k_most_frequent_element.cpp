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
    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    map<int, int> freq;
    rep(i, 0, n)
    {
        int l = freq.size();
        if (freq[a[i]] == 0 && l == k)
        {
            break;
        }
        freq[a[i]]++;
    }
    vii ans;
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        pii p;
        p.first = it->ss;
        p.second = it->ff;
        if (it->ss != 0)
        {
            ans.push_back(p);
        }
    }
    sort(ans.begin(), ans.end(), greater<pii>());
    vii ::iterator it1;
    for (it1 = ans.begin(); it1 != ans.end(); it1++)
    {
        cout << it1->ss << " " << it1->ff << endl; //here it1->ss is = it->ff which is the freq 1st element for which
        //frequqency is calculated
    }

    return 0;
}