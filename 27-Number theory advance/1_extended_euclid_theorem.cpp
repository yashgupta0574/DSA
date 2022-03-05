//multiplicative modulo inverse also
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

//ax+by=gcd(a,b)
//gcd(d,0)=d

struct triplet
{
    int x, y, gcd;
};

triplet extendedeuclid(int a, int b)
{
    triplet ans;
    if (b == 0)
    {
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }
    triplet smallans = extendedeuclid(b, a % b);
    ans.x = smallans.y;
    ans.y = smallans.x - (a / b) * smallans.y;
    ans.gcd = smallans.gcd;
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    triplet ans = extendedeuclid(a, b);
    cout << ans.x << " " << ans.y << " " << ans.gcd << endl;
    //here x is multiplicative modulo inverse m
    return 0;
}