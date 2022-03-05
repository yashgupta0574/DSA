// Pair Target Sum Problem
//  Array must be sorted
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, key;
    cin >> n >> key;
    cout << "Enter sorted array" << endl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] + a[j] == key)
        {
            cout << i << " " << j;
            return 0;
        }
        else if (a[i] + a[j] > key)
        {
            j--;
        }
        else if (a[i] + a[j] < key)
        {
            i++;
        }
        else
        {
            cout << "Key is not present";
        }
    }
    return 0;
}