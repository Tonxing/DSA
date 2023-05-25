#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    Rectangle r = {10, 5};
    cout << r.length << endl;
    cout << r.breadth << endl;

    Rectangle *p = &r;
    cout << p->length << endl;
    cout << p->breadth << endl;

    Rectangle *q;
    q = new Rectangle;
    q->length = 6;
    q->breadth = 3;
    cout << q->length * q->breadth << endl;

    return 0;
}