// Smallest positive missing number
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, ans;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ind[n];
    for (int j = 0; j < n; j++)
    {
        ind[j] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            ind[a[i]] = true;
        }
    }
    for (int j = 1; j < n; j++)
    {
        if (ind[j] == false)
        {
            ans = j;
            break;
        }
    }
    cout << ans;
    return 0;
}