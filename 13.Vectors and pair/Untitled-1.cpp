#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a;
    int temp;
    for (int i = 0; i < 3; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    vector<int> b;
    for (int i = 0; i < 3; i++)
    {
        cin >> temp;
        b.push_back(temp);
    }
    // compareTriplets(a,b);
    vector<int> best(2, 0);
    int x = 0, y = 0;
    for (int i = 0; i < 3; i++)
    {
        int q = a[i];
        int w = b[i];
        if (q > w)
        {
            best[0]++;
        }
        else if (w > q)
        {
            best[1]++;
        }
    }
    cout << best[0] << " " << best[1];
    return 0;
}