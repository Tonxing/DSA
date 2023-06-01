#include <iostream>
using namespace std;

void Duplicate(int A[], int n)
{
    int lastDuplicate = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == A[i + 1] && A[i] != lastDuplicate)
        {
            cout << A[i] << " " << endl;
            lastDuplicate = A[i];
        }
    }
}

void DuplicateCount(int A[], int n)
{
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == A[i + 1])
        {
            j = i + 1;
            while (A[j] == A[i])
                j++;
            cout << A[i] << " is appearing " << j - i << " times" << endl;
            i = j - 1;
        }
    }
}

int main()
{
    int A[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    Duplicate(A, 10);
    DuplicateCount(A, 10);
}

// Time complexity = O(n)