#include <bits/stdc++.h>
using namespace std;

void max_subarray_sum(int arr[], int n, int k, int x)
{
    int ans = 0, sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    if (sum < x)
    {
        ans = sum;
    }
    for (int i = k; i < n; i++)
    {
        sum -= arr[i - k];
        sum += arr[i];
        if (sum < x)
        {
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}

int main()
{
    int arr[] = {7, 5, 4, 6, 8, 9};
    max_subarray_sum(arr, 6, 3, 20);
    return 0;
}