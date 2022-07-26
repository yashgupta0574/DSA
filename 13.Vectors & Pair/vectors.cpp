#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    } // 1 2 3

    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    } // 1 2 3

    for (auto element : v)
    {
        cout << element << endl;
    } // 1 2 3

    v.pop_back(); // 1 2

    vector<int> v2(3, 100);
    // 100 100 100

    swap(v, v2); // v become v2 and v2 will become v

    for (auto element : v)
    {
        cout << element << endl;
    } // 100 100 100

    for (auto element : v2)
    {
        cout << element << endl;
    } // 1 2

    vector<int> v3; // for taking input and output
    int x;
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        v3.push_back(x);
    }
    int sum = accumulate(v3.begin(), v3.end(), 0); // include "numeric" library file
    cout << "Sum=" << sum << endl;

    int mx = *max_element(v3.begin(), v3.end());
    int mn = *min_element(v3.begin(), v3.end());
    cout << "Max=" << mx << endl;
    cout << "Min=" << mn << endl;

    partial_sum(v3.begin(), v3.end(), v3.begin()); // convert in prefix sum like input is 1 2 3 4 then ans will be 1 3 6 10

    /*sort(v3.begin(), v3.end());
    cout << "Sorted array is:" << endl;*/
    for (int i = 0; i < 5; i++)
    {
        cout << v3[i] << " ";
    }
    return 0;
}