// In number theory, a perfect number is a positive
// integer that is equal to the sum of its positive divisors,
// excluding the number itself. For instance,
// 6 has divisors 1, 2 and 3, and 1 + 2 + 3 = 6, so 6 is a perfect number.
#include <bits/stdc++.h>
using namespace std;

int maxsum(int arr[], int n, int k)
{
    int ans = 0;
    int res = 0;
    for (int i = 0; i < k; i++)
    {
        res += arr[i];
    }
    ans = res;
    for (int j = k; j < n; j++)
    {
        res = res - arr[j - k] + arr[j];
        ans = max(ans, res);
    }
    return ans;
}

bool isperfect(int n)
{
    int sum = 1;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            sum += i + n / i;
        }
    }
    if (sum == n && n != 1)
    {
        return true;
    }
    return false;
}

int maxnoOfperfect(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (isperfect(arr[i]))
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }
    return maxsum(arr, n, k);
}

int main()
{
    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k = 4;
    int n = 8;
    cout << maxnoOfperfect(arr, n, k) << endl;
    return 0;
}