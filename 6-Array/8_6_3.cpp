#include <iostream>
#include <climits>
using namespace std;

int kadane(int a[], int n)
{
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
    return maxsum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int wrapsum;
    int nonwrapsum = kadane(a, n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        a[i] = -a[i];
    }
    wrapsum = sum + kadane(a, n);
    cout << max(wrapsum, nonwrapsum) << endl;

    return 0;
}