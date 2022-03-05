#include <iostream>
using namespace std;

class student
{
    string surname; // private

public: // if public is not mention here the all data members will be private and we cannot acess them outside this class
    string name;
    int age;
    bool gender;

    student()
    {
        cout << "Default constructor" << endl;
    } // default constructor

    student(string s, int a, bool g)
    {
        cout << "Parameterized constructor" << endl;
        name = s;
        age = a;
        gender = g;
    } // parameterized constructor

    student(student &a)
    {
        cout << "Copy constructor" << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    } // copy constructor

    ~student()
    {
        cout << "Destructor called" << endl;
    }

    bool operator==(student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        return false;
    }

    void setname(string s)
    {
        surname = s; // use to assign the data type which is private
    }
    void getname()
    {
        cout << surname << endl; // can also be print using cout in printinfo function
    }

    void printinfo()
    {
        cout << "name=" << name << endl;
        cout << "surname=" << surname << endl; // can also be print using getname function
        cout << "age=" << age << endl;
        cout << "gender=" << gender << endl;
    }
};
int main()
{
    /*student a;
    a.name="Yash";
    a.age=18;
    a.gender=0;*/
    // only single data input

    /*student arr[2];
    for (int i = 0; i < 2; i++)
    {
        string s;
        cin >> s;
        arr[i].setname(s);
        cin >> arr[i].name;
        cin >> arr[i].age;
        cin >> arr[i].gender;
    }

    for (int i = 0; i < 2; i++)
    {
        arr[i].printinfo();
    }*/

    student a("Yash", 18, 0);
    // a.printinfo();
    student b("Aa", 10, 1);
    student c = a;
    // c.printinfo();

    if (c == a)
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }

    return 0;
}