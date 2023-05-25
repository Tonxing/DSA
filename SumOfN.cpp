#include <iostream>

using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
        return sum(n - 1) + n;
}

int sum2(int n)
{
    return n * (n + 1) / 2;
}

int main()
{
    int x;
    x = sum(5);
    cout << x;

    cout << " ";

    int y;
    y = sum2(6);
    cout << y;
}