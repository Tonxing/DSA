#include <iostream>

using namespace std;

int pow(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return pow(m * m, n / 2);
    else
        return m * pow(m * m, n / 2);
}

int pow1(int m, int n)
{
    if (n == 0)
        return 1;
    return pow1(m, n - 1) * m;
}

int main()
{
    int m = 2, n = 4;
    int z = pow(m, n);
    cout << z;

    cout << " ";

    int y = pow1(2, 8);
    cout << y;
}