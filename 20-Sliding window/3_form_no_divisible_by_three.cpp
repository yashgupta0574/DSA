#include <bits/stdc++.h>
using namespace std;

void form_number(vector<int> arr, int k)
{
    pair<int, int> ans;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    bool found = false;
    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = true;
    }
    for (int j = k; j < arr.size(); j++)
    {
        if (found)
        {
            break;
        }
        sum = sum - arr[j - k] + arr[j];
        if (sum % 3 == 0)
        {
            ans = make_pair(j - k + 1, j);
            found = true;
            break;
        }
    }
    for (int i = ans.first; i <= ans.second; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {84, 23, 45, 12, 56, 82};
    int k = 3; //no of integer we want in pair
    form_number(arr, k);
    return 0;
}