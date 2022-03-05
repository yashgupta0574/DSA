// to check if array is sorted or not
#include <iostream>
using namespace std;

bool sorted(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    bool restArray = sorted(arr + 1, n - 1);
    return (arr[0] < arr[1] && restArray);
}

int main()
{
    int a[] = {1, 2, 3, 6, 5};
    cout << sorted(a, 5) << endl;
    return 0;
}