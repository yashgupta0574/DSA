#include <iostream>
using namespace std;

long long merge(int arr[], int l, int mid, int r)
{
    long long inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }
    int x = 0, y = 0, k = l;
    while (x < n1 && y < n2)
    {
        if (a[x] < b[y])
        {
            arr[k] = a[x];
            k++;
            x++;
        }
        if (b[y] < a[x])
        {
            inv += n1 - x;
            arr[k] = b[y];
            k++;
            y++;
        }
    }
    while (x < n1)
    {
        arr[k] = a[x];
        k++;
        x++;
    }
    while (y < n2)
    {
        arr[k] = b[y];
        k++;
        y++;
    }
    return inv;
}

long long mergesort(int arr[], int l, int r)
{
    long long inv = 0;
    int mid;
    if (l < r)
    {
        mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << mergesort(arr, 0, n - 1);

    return 0;
}