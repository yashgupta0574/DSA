#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int a = 0;
  int b = 1;
  cout << "0 "
       << "1 ";
  int sum;
  for (int i = 1; i < (n - 1); i++)
  {
    sum = a + b;
    a = b;
    b = sum;
    cout << sum << " ";
  }

  return 0;
}
