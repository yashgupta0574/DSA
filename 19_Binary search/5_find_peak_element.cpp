#include <bits/stdc++.h>
using namespace std;

int findPeakelement(int arr[], int n, int left, int right)
{
    if (left > right)
    {
        return -1;
    }
    int mid = (left + right) / 2;
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
    {
        return arr[mid];
    }
    else if (arr[mid - 1] > arr[mid])
    {
        return findPeakelement(arr, n, left, mid - 1);
    }
    else
    {
        return findPeakelement(arr, n, mid + 1, right);
    }
}

int main()
{
    int arr[] = {5, 7, 9, 11, 15, 20, 25, 2, 4, 7};
    cout << findPeakelement(arr, 9, 0, 9) << endl;
    return 0;
}