#include <iostream>
using namespace std;
// difference of  index and element
int Difference(int A[], int l, int h, int n)
{
    int diff = l - 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] - i != diff)
        {
            while (diff < A[i] - i)
            {
                cout << i + diff << " ";
                diff++;
            }
        }
    }
}

int main()
{
    int A[11] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    Difference(A, 6, 19, 11);
}

// Time complexity O(n)