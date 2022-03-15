#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // string str(5,'n');
    // cout<<str<<endl;

    // string s;
    // getline(cin,s);

    /*1.append
    string s1="fam",s2="ily";
    //s1.append(s2);
    //cout<<s1<<endl;
    //cout<<s1+s2<<endl;
    cout<<s1<<s2;*/

    /*2.assign
     string s="sucessful";
     //s.assign("Yash");
     //s="Yash";
     cout<<s<<endl;*/

    /*3.at
    string s="Yash";
    cout<<s.at(3)<<endl;
    cout<<s[3]<<endl;*/

    // 4.begin
    /*string s="Yash";
    cout<<*s.begin()<<endl;
    string str="B Language";
    *str.begin()='C';
    cout<<str<<endl;*/

    // 5.clear
    /*string s="Yash";
    s.clear();
    cout<<s<<endl;
    s="Hello";
    cout<<s<<endl;*/

    // 6.compare
    /*string s1="abc",s2="xyz",s3="abc";
    cout<<s2.compare(s1)<<endl;
    cout<<s1.compare(s2)<<endl;
    cout<<s3.compare(s1)<<endl;*/

    // 7.c_str  {convert string into character array i.e add a null character(\0) at the end of given string}

    // 8.empty
    /*string s="Yash";
    s.clear();
    if(s.empty()){
    cout<<"given string is empty"<<endl;}*/

    // 9.end

    // 10.erase
    string s = "ABCDEFGH";
    s.erase(2, 4);
    cout << s << endl;

    // 11.find
    /*string s="ABCDEFGH";
    cout<<s.find("CD")<<endl;
    string str="yobro";
    cout<<str.find("o")<<endl;*/

    // 12.insert
    /*string s="Ggle";
    s.insert(1,"oo");
    cout<<s<<endl;*/

    // 13.size
    /*string s="ABCDEFGH";
    cout<<s.size()<<endl;*/

    // 14.length
    /*string s1="ABCDEFGH";
    cout<<s1.length()<<endl;*/

    // 15.resize
    /*string s="ABCDEFGH";
    s.resize(5);
    cout<<s<<endl;*/

    // 16.substring
    /*string s="ABCDEFGH";
    cout<<s.substr(2,4)<<endl;*/

    // 17.stoi
    /*string s="542";
    int x=stoi(s);
    cout<<x+5<<endl;*/

    // 18.to_string
    /*int x=145;
    cout<<to_string(x)+"75"<<endl;
    cout<<to_string(x)+'7'<<endl;*/

    // 19.sort                                 {we include header file name as algorithm}
    // string s = "vgytrsawb";
    // sort(s.begin(), s.end());
    // cout << s << endl;
    /*string s;
    getline(cin, s);
    cout << s[1];*/

    return 0;
}
