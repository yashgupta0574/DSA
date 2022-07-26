#include <bits/stdc++.h>
using namespace std;

bool isfeasible(int arr[], int n, int k, int mid)
{
    int pos = arr[0], element = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - pos) >= mid)
        {
            element++;
            pos = arr[i];
            if (element == k)
            {
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int result = -1;
    int left = arr[0], right = arr[n - 1];
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isfeasible(arr, n, k, mid))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return result;
}

int main()
{
    int arr[] = {2, 3, 5, 9, 11, 20};
    cout << largestMinDistance(arr, 6, 3);
    return 0;
}