#include <iostream>
using namespace std;

template <class T>
class Rectangle
{
private:
    T l;
    T b;

public:
    Rectangle(T l, T b);
    T area();
    T perimeter();
};

template <class T>
Rectangle<T>::Rectangle(T l, T b)
{
    this->l = l;
    this->b = b;
}

template <class T>
T Rectangle<T>::area()
{
    T c;
    c = l * b;
    return c;
}

template <class T>
T Rectangle<T>::perimeter()
{
    T c;
    c = 2 * (l + b);
    return c;
}

int main()
{
    Rectangle<float> r(5.5, 2.5);
    cout << r.area() << endl;
    cout << r.perimeter() << endl;
    return 0;
}