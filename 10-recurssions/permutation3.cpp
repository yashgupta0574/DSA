#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> permute(vector<int> nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    do
    {
        ans.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return ans;
}

int main()
{
    vector<vector<int>> res = permute({1, 2, 2, 3});
    for (auto i : res)
    {
        for (auto ii : i)
        {
            cout << ii << " ";
        }
        cout << "\n";
    }
}
