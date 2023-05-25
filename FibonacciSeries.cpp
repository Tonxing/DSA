#include <iostream>

using namespace std;

// iteration
int fib1(int n)
{
    int a = 0, b = 1, s;

    if (n <= 1)
    {
        return n;
    }
    for (int i = 2; i <= n; i++)
    {
        s = a + b;
        a = b;
        b = s;
    }
    return s;
}

// recursion
int fib2(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib2(n - 2) + fib2(n - 1);
}

// memorization
int M[10];

int fib3(int n)
{
    if (n <= 1)
    {
        M[n] = n;
        return n;
    }
    else
    {
        if (M[n - 2] == -1)
            M[n - 2] = fib3(n - 2);
        if (M[n - 1] == -1)
            M[n - 1] = fib3(n - 1);
        return M[n - 2] + M[n - 1];
    }
}

int main()
{
    cout << fib1(7) << endl;
    cout << fib2(6) << endl;

    for (int i = 0; i < 10; i++)
        M[i] = -1;
    cout << fib3(5) << endl;
}