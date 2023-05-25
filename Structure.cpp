#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r = {4, 2};
    cout << r.length * r.breadth << endl;
}