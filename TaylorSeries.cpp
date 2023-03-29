#include <iostream>

using namespace std;
// Basic
int e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    else
    {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}

// Honer's Rule

// iterative
int e1(int x, int n)
{
    int s = 1;
    for (; n > 0; n--)
    {
        s = 1 + x / n * s;
    }
    return s;
}

// Recursive
double e2(int x, int n)
{
    static double z = 1;
    if (n == 0)
        return z;
    z = 1 + x * z / n;
    return e2(x, n - 1);
}

// iterative or loop
double e3(int x, int n)
{
    double s = 1;
    int i;
    double num = 1;
    double den = 1;
    for (i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

int main()
{
    cout << e(4, 10);
    cout << " ";
    cout << e1(4, 10);
    cout << " ";
    cout << e2(2, 10);
    cout << " ";
    cout << e3(2, 10);
}