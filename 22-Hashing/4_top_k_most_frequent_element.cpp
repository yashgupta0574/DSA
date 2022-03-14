// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define pii pair<int, int>
// #define vii vector<pii>
// #define ff first
// #define ss second
// #define rep(i, a, b) for (int i = a; i < b; i++)

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     int a[n];
//     rep(i, 0, n)
//     {
//         cin >> a[i];
//     }
//     map<int, int> freq;

//     rep(i, 0, n)
//     {
//         int l = freq.size();
//         if (freq[a[i]] == 0 && l == k)
//             break;
//         freq[a[i]]++;
//     }

//     vii ans;
//     map<int, int>::iterator it;

//     for (it = freq.begin(); it != freq.end(); it++)
//     {
//         pii p;
//         p.first = it->ss;
//         p.second = it->ff;
//         if (it->ss != 0)
//             ans.push_back(p);
//     }

//     sort(ans.begin(), ans.end(), greater<pii>());
//     vii ::iterator it1;
//     for (it1 = ans.begin(); it1 != ans.end(); it1++)
//     {
//         cout << it1->ss << " " << it1->ff << endl;
//         // here it1->ss is = it->ff which is the freq 1st element for which
//         // frequqency is calculated
//     }

//     return 0;
// }

// C++ implementation to find k numbers with most
// occurrences in the given array
#include <bits/stdc++.h>

using namespace std;

struct compare
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        // if frequencies of two elements are same
        // then the larger number should come first
        if (p1.second == p2.second)
            return p1.first < p2.first;
        // insert elements in the priority queue on the basis of
        // decreasing order of frequencies
        return p1.second < p2.second;
    }
};

// function to print the k numbers with most occurrences
void print_N_mostFrequentNumber(int arr[], int n, int k)
{
    // unordered_map 'um' implemented as frequency hash table
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
        um[arr[i]]++;

    // priority queue 'pq' implemented as max heap on the basis
    // of the comparison operator 'compare'
    // element with the highest frequency is the root of 'pq'
    // in case of conflicts, larger element is the root
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> // maxheap
        pq(um.begin(), um.end());

    cout << k << " numbers with most occurrences are:\n";
    for (int i = 1; i <= k; i++)
    {
        cout << pq.top().first << " ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    print_N_mostFrequentNumber(arr, n, k);
    return 0;
}