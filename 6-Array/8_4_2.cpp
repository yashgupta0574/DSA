// longest arithmetic subarray
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int pd = a[1] - a[0];
    int count = 2, j = 2, ans = 2;
    while (j < n)
    {
        if ((a[j] - a[j - 1]) == pd)
        {
            count++;
        }
        else
        {
            pd = a[j] - a[j - 1];
            count = 2;
        }
        ans = max(ans, count);
        j++;
    }
    cout << ans;
    return 0;
}