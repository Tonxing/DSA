#include <iostream>
using namespace std;

int main()
{
    int A[10] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    // Hash table or Bit set
    int H[13] = {0};
    int l = 1, h = 12, n = 10;
    int i;
    for (i = 0; i < n; i++)
    {
        H[A[i]]++;
    }
    for (i = l; i <= h; i++)
    {
        if (H[i] == 0)
        {
            cout << i << " ";
        }
    }
}

// Time complexity O(n)