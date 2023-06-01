#include <iostream>
using namespace std;

int SumFirstN(int A[], int n, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + A[i];
    }
    int s = n * (n + 1) / 2;
    int result = s - sum;

    return result;
}

int Difference(int B[], int l, int h, int size)
{
    int diff = l - 0;
    for (int i = 0; i < size; i++)
    {
        if (B[i] - i != diff)
        {
            return i + diff;
        }
    }
}

int main()
{
    int A[11] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    int B[11] = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};

    int missingA = SumFirstN(A, 12, 11);
    cout << missingA << endl;

    int missingB = Difference(B, 6, 17, 11);
    cout << missingB << endl;
}