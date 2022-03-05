// First repeating element
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, mindx = INT_MAX;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ind[n];
    for (int j = 0; j < n; j++)
    {
        ind[j] = {-1};
    }
    for (int i = 0; i < n; i++)
    {
        if (ind[a[i]] == -1)
        {
            ind[a[i]] = i;
        }
        else
        {
            mindx = min(mindx, ind[a[i]]);
        }
    }
    cout << mindx + 1;
    return 0;
}