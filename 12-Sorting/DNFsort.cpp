#include <iostream>
#include <algorithm>
using namespace std;
void swap(int arr[], int mid, int l)
{
    int temp = arr[mid];
    arr[mid] = arr[l];
    arr[l] = temp;
}
void DNFsort(int arr[], int n)
{
    int l = 0, mid = 0, r = n - 1;
    while (mid <= r)
    {
        if (arr[mid] == 0)
        {
            swap(arr, mid, l);
            mid++;
            l++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr, mid, r);
            r--;
        }
    }
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
    DNFsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}