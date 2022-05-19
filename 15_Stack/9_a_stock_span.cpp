#include <bits/stdc++.h>
using namespace std;

vector<int> stockspan(vector<pair<int, int>> v)
{
    int i = 1;
    stack<int> st;
    st.push(v[0].first);
    vector<int> ans;
    ans.push_back(1);
    while (i < v.size())
    {
        if (v[i].first <= st.top())
        {
            st.push(v[i].first);
            ans.push_back(v[i].second);
        }
        else
        {
            int j = i - 1;
            int temp = 1;
            while (j != 0 && v[i].first > st.top())
            {
                temp += v[j].second;
                v[i].second = temp;
                st.pop();
                j--;
            }
            st.push(v[i].first);
            ans.push_back(v[i].second);
        }
        i++;
    }
    return ans;
}

int main()
{
    vector<int> inp{100, 80, 60, 70, 60, 75, 85};
    vector<pair<int, int>> vec;
    for (int i = 0; i < inp.size(); i++)
    {
        vec.push_back(make_pair(inp[i], 1));
    }
    vector<int> res = stockspan(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}