#include <iostream>

using namespace std;

int main()
{
    int *p = new int[5];
    int *q = new int[10];
    int i;
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;
    for (i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    delete[] p;
    p = q;
    q = NULL;
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", p[i]);
    }
    return 0;
}
