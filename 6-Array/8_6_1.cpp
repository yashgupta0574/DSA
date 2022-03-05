// Prefix sum technique O(n2)
// Valid when max sum is negative too i.e when all nos are negative
#include <iostream>
#include <climits>
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
    int add[n + 1];
    add[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        add[j] = add[j - 1] + a[j - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << add[i] << " ";
    }
    int maxsum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        maxsum = max(maxsum, add[i]);
        for (int j = 1; j < i; j++)
        {
            sum = add[i] - add[j];
            maxsum = max(maxsum, sum);
        }
    }
    cout << endl
         << maxsum;

    return 0;
}