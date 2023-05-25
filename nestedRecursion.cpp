#include <iostream>

using namespace std;

int fun(int value)
{
    if (value > 100)
        return value - 10;
    else
        return fun(fun(value + 11));
}

int main()
{
    int n;
    n = fun(200);
    cout << n;
    return 0;
}