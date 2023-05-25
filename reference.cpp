#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &r = a;
    r = 12;

    int b = 7;
    r = b;
    cout << a << endl
         << r << endl;
}