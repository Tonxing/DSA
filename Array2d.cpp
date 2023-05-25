#include <iostream>
using namespace std;
int main()
{
    int X[3][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << X[i][j] << "\n";
        }
    }

    int *A[3];
    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];

    int **B;
    B = new int *[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    return 0;
}