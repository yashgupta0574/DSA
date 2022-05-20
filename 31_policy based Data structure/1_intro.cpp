#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;

template <class T>
using yashset = tree<T, null_type, less<T>,
                     rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    int q;
    cin >> q;
    yashset<int> s;
    while (q--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int t;
            cin >> t;
            s.insert(t);
        }
        else if (c == 2)
        {
            int t;
            cin >> t;
            cout << *s.find_by_order(t) << endl;
        }
        else // c==3
        {
            int t;
            cin >> t;
            cout << s.order_of_key(t) << endl;
        }
    }
    return 0;
}
/*
7
1 1
1 2
1 4
2 1
1 8
1 16
3 16
*/