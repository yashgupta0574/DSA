#include <iostream>
using namespace std;
int main()
{

  int number;
  int sum = 0;

  cout << "enter a number";
  cin >> number;

  while (number >= 0)
  {
    sum += number;
    cout << "enter a number";
    cin >> number;
  }

  cout << "\n the sum is" << sum << endl;

  return 0;
}