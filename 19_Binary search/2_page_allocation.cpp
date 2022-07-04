#include <bits/stdc++.h>
using namespace std;

bool isfeasible(int arr[], int n, int m, int min)
{
    int stud_req = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            return false;
        }
        if (arr[i] + sum > min)
        {
            stud_req++;
            sum = arr[i];
            if (stud_req > m)
            {
                return false;
            }
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int allocateMinPages(int arr[], int n, int m)
{
    if (n < m)
    {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int minm = arr[0], maxm = sum, ans = INT_MAX;
    while (minm < maxm)
    {
        int mid = (minm + maxm) / 2;
        if (isfeasible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            maxm = mid;
        }
        else
        {
            minm = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60}; // arr should be ascending if not then sort it
    cout << allocateMinPages(arr, 6, 4);
    return 0;
}