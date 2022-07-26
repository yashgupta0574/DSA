#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void prev_small(vector<int> &ps, int hist[])
{
    stack<int> st;
    for (int i = 0; i < ps.size(); i++)
    {
        while (!st.empty() && hist[st.top()] >= hist[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ps[i] = -1;
        }
        else
        {
            ps[i] = st.top();
        }
        st.push(i);
    }
}

void next_small(vector<int> &ns, int hist[])
{
    stack<int> st;
    for (int i = ns.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && hist[st.top()] >= hist[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ns[i] = ns.size();
        }
        else
        {
            ns[i] = st.top();
        }
        st.push(i);
    }
}

int getArea(int hist[], int n)
{
    vector<int> ps(n, 0);
    for (int i = 0; i < ps.size(); i++)
    {
        ps[i] = hist[i];
    }
    prev_small(ps, hist);

    vector<int> ns(n, 0);
    for (int i = 0; i < ns.size(); i++)
    {
        ns[i] = hist[i];
    }
    next_small(ns, hist);

    //****************************************//
    // for (int i = 0; i < ps.size(); i++)
    // {
    //     cout << ps[i] << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < ns.size(); i++)
    // {
    //     cout << ns[i] << " ";
    // }
    // cout << endl;
    //****************************************//

    int largest_area = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_area = (ns[i] - ps[i] - 1) * hist[i];
        cout << curr_area << " ";
        largest_area = max(largest_area, curr_area);
    }
    return largest_area;
}

int main()
{
    int hist[] = {1, 2, 2, 6, 7, 4, 5, 3, 2};
    int n = sizeof(hist) / sizeof(hist[0]);
    cout << "Largest area is:" << getArea(hist, n);
    return 0;
}