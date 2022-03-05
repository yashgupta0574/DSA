#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void countsort(int arr[], int n)
{
    int k = arr[0]; // k=maximum element of array

    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }

    vector<int> count(100);
    count.resize(k + 1);
    // int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = (n - 1); i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
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
    // int arr[] = {1, 2, 4, 2, 4, 5, 6, 3, 4};
    countsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
