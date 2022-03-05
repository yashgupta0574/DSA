#include <iostream>

using namespace std;
int getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int setbit(int n, int pos)
{
    return (n | (1 << pos));
}

int clearbit(int n, int pos)
{
    int mask = ~(1 << pos);
    return (n & mask);
}

int updatebit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = n & mask;
    return (n | (value << pos));
}

int togglebit(int n, int pos)
{
    return (n xor (1 << pos));
}

int setBitNumber(int n)
{
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n = n + 1;
    return (n >> 1);
}

int main()
{
    // cout<<getbit(5,1)<<endl;     {gives the bit present at the given postion}
    // cout<<setbit(5,3)<<endl;     {set the bit at given postion i.e it sets 1 at that position.Unset means put 0 at that psoition}
    // cout<<clearbit(5,0)<<endl;   {sets 0 at that position}
    // cout<<updatebit(5,1,1)<<endl; {update the given bit at that position}
    // cout<<togglebit(5,1)<<endl;   {toggle =switch}

    int x = 4;
    // Number of leading zeroes:
    cout << __builtin_clz(x) << endl;
    // Number of trailing zeroes:
    cout << __builtin_ctz(x) << endl;
    // Number of 1-bits:
    cout << __builtin_popcount(x) << endl;
    // Number of bits of 1 is odd then it returns 1 else it returns 0
    cout << __builtin_parity(x) << endl;

    // binary to decimal conversion
    int num = 0b1001;
    cout << num << endl;

    // swap using xor
    /*int a=50,b=100;
    a^=b;
    b^=a;
    a^=b;
    cout<<a<<endl<<b<<endl;*/

    // To find the power of 2, smaller than the given number
    cout << setBitNumber(65) << endl;

    // to reverse the bits and print it in decimal form
    /*unsigned int x=1,rev=0;
    for(int i=0;i<32;i++){
        if( (x & (1<<i)) ){
            rev= (rev | 1<<(31-i)) ;
        }
    }*/

    // to find hamming distance b/w 2 nos i.e the number of digits at which bits are different
    /*int x,y,z;
    cin>>x>>y;
    z=x^y;
    cout<<__builtin_popcount(z)<<endl;*/
    return 0;
}