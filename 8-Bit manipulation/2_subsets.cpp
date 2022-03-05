#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    /*int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<a[j]<<" ";
            }
        }cout<<endl;
    }*/

    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << s[j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}