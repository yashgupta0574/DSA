#include <bits/stdc++.h>
using namespace std;

vector<int> max_in_k(int arr[], int n, int k)
{
    deque<int> d;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        while (!d.empty() && arr[d.back()] < arr[i])
        {
            d.pop_back();
            // other functions of deque are pop_front push_front and push_back
        }
        d.push_back(i);
    }
    ans.push_back(arr[d.front()]);
    for (int i = k; i < n; i++)
    {
        while (d.front() <= i - k)
        {
            d.pop_front();
        }
        while (!d.empty() && arr[d.back()] < arr[i])
        {
            d.pop_back();
        }
        d.push_back(i);
        ans.push_back(arr[d.front()]);
    }
    return ans;
}

int main()
{
    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> res = max_in_k(arr, n, k);
    for (auto &i : res)
    {
        cout << i << " ";
    }
    return 0;
}