#include <bits/stdc++.h>
using namespace std;

int smallest_subarray_sum_greater_than_x(int arr[], int n, int x)
{
    int ans = n + 1, sum = 0, start = 0, end = 0; // ans=minlength
    while (end < n)
    {
        while (end < n && sum < x)
        {
            sum += arr[end++];
        }
        while (sum > x && start < n)
        {
            ans = min(ans, end - 1 - start);
            sum -= arr[start++];
        }
    }
    return ans;
}

int main()
{
    int arr[] = {2, 45, 1, 8, 18, 30};
    cout << smallest_subarray_sum_greater_than_x(arr, 6, 55) << endl;
    return 0;
}