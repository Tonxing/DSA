#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap1(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void fun(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << endl;
}

int area(struct Rectangle r1)
{
    r1.length++;
    return r1.length * r1.breadth;
}

void changeLength(struct Rectangle *r2, int l)
{
    r2->length = l;
}

int main()
{
    int a = 6, b = 9;
    swap(&a, &b);
    cout << a << b << endl;

    int x = 6, y = 9;
    swap1(x, y);
    cout << "First number" << x << endl;
    cout << "Second number" << y << endl;

    int A[] = {3, 6, 7, 2, 1, 22};
    int n = 6;
    fun(A, n);

    struct Rectangle r = {10, 5};
    cout << area(r) << endl;
    cout << r.length << endl;
    changeLength(&r, 20);
    cout << r.length << endl;
    return 0;
}