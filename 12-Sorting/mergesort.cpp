#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
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
}

void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
    return;
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
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}