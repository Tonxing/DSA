#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int num1 = 6, num2 = 4, sum;
    sum = add(num1, num2);
    cout << sum << endl;
    return 0;
}