#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(int num, int k)
{
    int temp = num, number = 0;
    while (temp > 0)
    {
        number = number * 10 + temp % 10;
        temp /= 10;
    }
    if (number == num)
    {
        return true;
    }
    return false;
}

int palindrome(vector<int> arr, int k)
{
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        num = num * 10 + arr[i];
    }
    if (ispalindrome(num, k))
    {
        return 0;
    }
    for (int i = k; i < arr.size(); i++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + arr[i];
        if (ispalindrome(num, k))
        {
            return i - k + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int k = 4;
    int ans = palindrome(arr, k);
    if (ans == -1)
    {
        cout << "No palindrome exist" << endl;
    }
    else
    {
        for (int i = ans; i < ans + k; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}