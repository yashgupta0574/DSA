// firstocc_lastocc
#include <iostream>
using namespace std;

int firstocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return firstocc(arr, n, i + 1, key);
}

int lastocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int restArray = lastocc(arr, n, i + 1, key);
    if (restArray != -1)
    {
        return restArray;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}

int main()
{
    int n, i = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;
    cout << firstocc(a, n, i, key) << endl;
    cout << lastocc(a, n, i, key) << endl;
    return 0;
}