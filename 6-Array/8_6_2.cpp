// kadane algorithm
// not valid for all negative numbers
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
    int maxsum = INT_MIN;
    int currentsum = 0;
    for (int i = 0; i < n; i++)
    {
        currentsum += a[i];
        if (currentsum < 0)
        {
            currentsum = 0;
        }
        maxsum = max(maxsum, currentsum);
    }
    cout << maxsum;
    return 0;
}