#include <iostream>
#include <stack>
using namespace std;

// using array preprocessing
int getvol_array(int rainwater[], int n)
{
    int left[n], right[n]; // larger in left side and right side
    left[0] = rainwater[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], rainwater[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << left[i] << " ";
    }
    cout << endl;
    right[n - 1] = rainwater[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], rainwater[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << right[i] << " ";
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += abs((min(left[i], right[i]) - rainwater[i]));
    }
    return sum;
}

// using stack
int getvol(int rainwater[], int n)
{
    stack<int> st;
    int i = 0, ans = 0;
    while (i < n)
    {
        if (st.empty() || rainwater[st.top()] > rainwater[i])
        {
            st.push(i++);
        }
        else
        {
            int curr = st.top();
            st.pop();
            if (st.empty())
            {
                continue;
            }
            int diff = i - st.top() - 1;
            int mult = (min(rainwater[st.top()], rainwater[i]) - rainwater[curr]);
            ans += (mult > 0 ? mult : -mult) * diff;
        }
    }
    return ans;
}

int main()
{
    int rainwater[] = {3, 1, 2, 4, 0, 1, 3, 2};
    int n = sizeof(rainwater) / sizeof(rainwater[0]);
    // cout << "Rainwater is " << getvol(rainwater, n) << endl;
    cout << "Rainwater is " << getvol_array(rainwater, n);
    return 0;
}