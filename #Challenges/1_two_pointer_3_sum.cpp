//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, target, temp;
    cin >> n;
    cin >> target;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    int found = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    for (int i = 0; i < n - 2; i++)
    {
        int lo = i + 1;
        int hi = n - 1;
        while (lo < hi)
        {
            if ((a[i] + a[lo] + a[hi]) == target)
            {
                found = 1;
                cout << found << endl;
                break;
            }
            else if ((a[i] + a[lo] + a[hi]) < target)
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }
    }

    if (found == 1)
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    return 0;
}