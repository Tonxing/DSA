#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 10;
    int *p;
    p = &a;

    cout << a << endl;
    printf("using pointer %d %d\n", *p, p);

    // pointer in array
    int A[5] = {4, 7, 4, 3, 2};
    int *y;
    y = A;
    for (int i = 0; i < 5; i++)
        cout << y[i] << endl;

    // Array pointer in heap
    int *z;
    int *h;
    z = (int *)malloc(5 * sizeof(int)); // c
    h = new int[5];                     // cpp

    z[0] = 12;
    z[1] = 3;
    z[2] = 7;
    z[3] = 9;
    z[4] = 16;
    for (int i = 0; i < 5; i++)
        cout << z[i] << endl;
    free(z); // c

    h[0] = 2;
    h[1] = 3;
    h[2] = 6;
    h[3] = 9;
    h[4] = 6;
    for (int i = 0; i < 5; i++)
        cout << h[i] << endl;
    delete[] h; // cpp

    int *r;
    char *b;
    float *c;
    cout << sizeof(r) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;

    return 0;
}